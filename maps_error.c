/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:20:59 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/10 08:24:22 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	objetos_de_mapa(t_mapa *data)
{
	t_indices	indices;

	indices.j = 0;
	indices.end = 0;
	while (data->map[++indices.j])
	{
		indices.i = 0;
		while (data->map[indices.j][++indices.i])
		{
			if (data->map[indices.j][indices.i] == 'P')
			{
				data->x = indices.i;
				data->y = indices.j;
				data->player++;
			}
			else if (data->map[indices.j][indices.i] == 'C')
				data->colectables++;
			else if (data->map[indices.j][indices.i] == 'E')
				indices.end++;
		}
	}
	if (data->player != 1 || data->colectables < 1 || indices.end != 1)
	{
		ft_printf ("Error aca\n");
		exit (EXIT_FAILURE);
	}
}

 void	ft_check_borders(t_mapa *data)
{
    int x;
    int y;

    y = 0;
    while (y < data->height)  // Usamos 'height' para las filas
    {
        if ((int)ft_strlen(data->map[y]) != data->width)
            manejar_error("Error\nmap has to be rectangular\n");

        x = 0;
        while (x < data->width)  // Usamos 'width' para las columnas
        {
            if (data->map[y][x] != '0' && data->map[y][x] != '1' &&
                data->map[y][x] != 'C' && data->map[y][x] != 'P' &&
                data->map[y][x] != 'E')
                manejar_error("Error\nfor map '0','1','C','P','E' are valid\n");
            else if ((y == 0 || x == 0) && data->map[y][x] != '1')
                manejar_error("Error\nmap has to be surrounded by walls\n");
            else if ((y == data->height - 1 || x == data->width - 1) &&
                data->map[y][x] != '1')
                manejar_error("Error\nmap has to be surrounded by walls\n");
            x++;
        }
        y++;
    }
}

void	comprobacion_open_ber(t_mapa *data)
{
	size_t	longitud;

	longitud = ft_strlen(data->text);
	if (longitud < 4 || ft_strncmp(&data->text[longitud - 4], ".ber", 4) != 0)
	{
		ft_printf("Error: el archivo debe tener la extensión .ber\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("El archivo %s es válido\n", data->text);
}


