/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:20:59 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 00:25:37 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void maps_objects(t_mapa *data)
{
    t_indices indices;

    count_objects(data, &indices);  // Llamamos a la función para contar objetos
    validate_map(data, &indices);    // Llamamos a la función para validar el mapa
}

void	exit_error(const char *message)
{
	ft_printf("Error\n", message);
	exit(EXIT_FAILURE);
}

void	ft_check_borders(t_mapa *mapa)
{
	int	idx;

	idx = 0;
	while (idx < mapa->width)
	{
		if (mapa->map[0][idx] != '1' || mapa->map[mapa->height - 1][idx] != '1')
		{
			exit_error("Error: El borde superior o inferior no está cerrado.");
		}
		idx++;
	}
	idx = 0;
	while (idx < mapa->height)
	{
		if (mapa->map[idx][0] != '1' || mapa->map[idx][mapa->width - 1] != '1')
		{
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
