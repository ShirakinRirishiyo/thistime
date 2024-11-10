/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:59:46 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/07/23 16:59:46 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int open_file(const char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        manejar_error("Error al abrir el archivo");
        return -1; 
    }
    return fd;  
}

void find_px_py(t_mapa *data)  
{
    int x;
    int y;

    // Recorrer las filas (de 0 a height-1)
    for (y = 0; y < data->height; y++) {
        // Recorrer las columnas (de 0 a width-1)
        for (x = 0; x < data->width; x++) {
            // Verificar si el elemento actual es 'P'
            if (data->map[y][x] == 'P') {
                // Guardar las coordenadas del jugador en la estructura
                data->x = x;  // o data->i = x, dependiendo de qué prefieras para las coordenadas genéricas
                data->y = y;  // o data->j = y, dependiendo de qué prefieras para las coordenadas genéricas
                data->i = x;  // Si decides usar x para la coordenada 'i' del jugador
                data->j = y;  // Si decides usar y para la coordenada 'j' del jugador
            }
        }
    }
}

void free_double_p(t_mapa *data)
{
    int i;

    // Liberar las filas del mapa (suponiendo que map es una matriz dinámica)
    for (i = 0; i < data->height; i++) {
        free(data->map[i]);  // Liberar cada fila del mapa
    }
    
    // Liberar la memoria del mapa en sí
    free(data->map);
}

void calloc_failure(char *str)
{
    perror(str);  // Imprimir el error
    exit(EXIT_FAILURE);  // Terminar el programa con un código de salida de error
}

// Función para obtener dimensiones del mapa y validar su tamaño
void obtener_dimensiones_y_validar(t_mapa *data) {
    int fd = open(data->text, O_RDONLY);
    if (fd == -1)
        manejar_error("Error al abrir el archivo");

    data->height = 0;
    data->width = 0;
    char *line;

    // Leer cada línea para obtener ancho y alto del mapa
    while ((line = get_next_line(fd)) != NULL) {
        int len = ft_strlen(line);
        if (line[len - 1] == '\n')
            line[len - 1] = '\0';

        if (len > data->width)
            data->width = len - 1;

        data->height++;
        free(line);
    }
    close(fd);

    // Verificar si el mapa está vacío
    if (data->height == 0 || data->width == 0)
        manejar_error("Error: El mapa está vacío.");

    // Verificar si el mapa es demasiado grande
    if (data->height > MAX_MAP_HEIGHT || data->width > MAX_MAP_WIDTH)
        manejar_error("Error: El mapa es demasiado grande.");
}

// Función para asignar memoria para el mapa
void asignar_memoria_mapa(t_mapa *data) {
    data->map = (char **)malloc(sizeof(char *) * (data->height + 1));
    if (data->map == NULL)
        manejar_error("Error al asignar memoria para el mapa");
}

// Función para cargar el contenido del mapa en data->map
void cargar_contenido_mapa(t_mapa *data) {
    int fd = open(data->text, O_RDONLY);
    if (fd == -1)
        manejar_error("Error al abrir el archivo");

    char *line;
    int i = 0;

    // Leer cada línea y almacenarla en el mapa
    while ((line = get_next_line(fd)) != NULL) {
        int len = ft_strlen(line);
        if (line[len - 1] == '\n')
            line[len - 1] = '\0';

        data->map[i++] = ft_strdup(line);
        free(line);
    }
    data->map[i] = NULL; // Terminamos con un NULL en la última posición
    close(fd);
}

// Función principal para cargar el mapa
void load_map(t_mapa *data) {
    obtener_dimensiones_y_validar(data);
    asignar_memoria_mapa(data);
    cargar_contenido_mapa(data);
}

void ft_window_size(t_mapa *data)
{
    // Usar los valores de height y width ya establecidos en load_map
    data->size_x = data->width * SPRITE_SIZE;  // Ancho de la ventana
    data->size_y = data->height * SPRITE_SIZE; // Alto de la ventana

    // Debug para confirmar el tamaño de la ventana
    printf("Tamaño de la ventana - Ancho (size_x): %d, Alto (size_y): %d\n", data->size_x, data->size_y);
}



void free_map(t_mapa *data)
{
    int i = 0;
    while (data->map && data->map[i]) {
        free(data->map[i]);  // Liberamos cada línea del mapa
        i++;
    }
    free(data->map);  // Liberamos el puntero del mapa
}
