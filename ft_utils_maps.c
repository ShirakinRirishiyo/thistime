/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:49:45 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/10 05:16:18 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_map(t_mapa *data, t_mapa_info *info)
{
    info->fd = open(data->text, O_RDONLY);  // Abre el archivo de texto del mapa
    if (info->fd == -1)
        manejar_error_fd("Error al abrir el archivo de mapa.\n", -1, NULL);  // Error al abrir el archivo

    data->map = (char **)malloc(sizeof(char *) * (data->height + 1));  // Reserva espacio para el mapa
    if (!data->map)
        malloc_fail();  // Llama a una función que maneja el fallo de malloc

    info->i = 0;  // Inicializa el índice de la línea
}


void procesa_line(t_mapa *data, t_mapa_info *info)
{
    info->line_length = ft_strlen(info->line);  // Obtiene la longitud de la línea
    if (info->line[info->line_length - 1] == '\n')  // Si la línea termina en salto de línea
    {
        info->line[info->line_length - 1] = '\0';  // Elimina el salto de línea
        info->line_length--;  // Ajusta la longitud de la línea
    }

    if (info->line_length != data->width)  // Si la longitud de la línea no coincide con el ancho del mapa
    {
        free(info->line);  // Libera la memoria de la línea
        close(info->fd);  // Cierra el archivo
        manejar_error_fd("El archivo de mapa tiene líneas de longitud incorrecta.\n", info->fd, NULL);  // Llama a manejar_error_fd
    }
    data->map[info->i] = (char *)malloc(sizeof(char) * (data->width + 1));  // Reserva espacio para la línea en el mapa
    if (!data->map[info->i])
        malloc_fail();  // Llama a la función para manejar fallos de malloc

    ft_strlcpy(data->map[info->i], info->line, data->width + 1);  // Copia la línea al mapa
    // NO liberar info->line aquí
}


/*int check_map_content(t_mapa *data)
{
    t_map_counts counts = {0};  // Inicializar la estructura de contadores
    int error_found = 0;         // Variable para indicar si ocurrió algún error

    // Recorremos el mapa usando bucles while
    int y = 0;
    while (y < data->height)
    {
        int x = 0;
        while (x < data->width)
        {
            char cell = data->map[y][x];
            if (cell == 'P')      // Contar el jugador
                counts.player_count++;
            else if (cell == 'E') // Contar la salida
                counts.exit_count++;
            else if (cell == 'C') // Contar los coleccionables
                counts.collectable_count++;
            else if (cell != '1' && cell != '0') // Caracteres inválidos
            {
                error_found = 1;
                break; // Salir del bucle si encontramos un error
            }
            x++;
        }
        if (error_found)
            break; // Salir del bucle si encontramos un error
        y++;
    }

    if (counts.player_count != 1)
        error_found = 1;
    if (counts.exit_count != 1)
        error_found = 1;
    if (counts.collectable_count < 1)
        error_found = 1;
    if (error_found)
    {
        ft_printf("Error: El mapa tiene configuraciones inválidas.\n");
        return (0);  // Retorna 0 para indicar que la validación falló
    }
    data->player = counts.player_count;
    data->finish = counts.exit_count;
    data->colectables = counts.collectable_count;
    return (1); // Retorna 1 si el contenido del mapa es válido
}
*/