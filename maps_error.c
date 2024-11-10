/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:20:59 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/10 10:49:14 by dediaz-f         ###   ########.fr       */
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

void exit_error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

void ft_check_borders(t_mapa *mapa) 
{
    int idx;

    // Verificar la primera y última fila
    idx = 0;
    while (idx < mapa->width) {
        if (mapa->map[0][idx] != '1' || mapa->map[mapa->height - 1][idx] != '1') {
            exit_error("Error: El borde superior o inferior no está cerrado.");
        }
        idx++;
    }

    // Verificar la primera y última columna
    idx = 0;
    while (idx < mapa->height) {
        if (mapa->map[idx][0] != '1' || mapa->map[idx][mapa->width - 1] != '1') {
            exit_error("Error: El borde izquierdo o derecho no está cerrado.");
        }
        idx++;
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


