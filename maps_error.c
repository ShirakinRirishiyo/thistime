/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:20:59 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/10 10:37:20 by dediaz-f         ###   ########.fr       */
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
    data->y = 0;
    while (data->y < data->height)  // Usamos 'height' para las filas
    {
        if ((int)ft_strlen(data->map[data->y]) != data->width)
            manejar_error("Error\nmap has to be rectangular\n");

        data->x = 0;
        while (data->x < data->width)  // Usamos 'width' para las columnas
        {
            if (data->map[data->y][data->x] != '0' && data->map[data->y][data->x] != '1' &&
                data->map[data->y][data->x] != 'C' && data->map[data->x][data->y] != 'P' &&
                data->map[data->y][data->x] != 'E')
                manejar_error("Error\nfor map '0','1','C','P','E' are valid\n");
            else if ((data->y == 0 || data->x == 0) && data->map[data->y][data->x] != '1')
                manejar_error("Error\nmap has to be surrounded by walls\n");
            else if ((data->y == data->height - 1 || data->x == data->width - 1) &&
                data->map[data->y][data->x] != '1')
                manejar_error("Error\nmap has to be surrounded by walls\n");
            data->x++;
        }
        data->y++;
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


