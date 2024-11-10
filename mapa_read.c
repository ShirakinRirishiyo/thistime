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

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		handle_error("Error al abrir el archivo");
		return (-1);
	}
	return (fd);
}

void	find_px_py(t_mapa *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == 'P')
			{
				data->x = x;
				data->y = y;
				data->i = x;
				data->j = y;
			}
			x++;
		}
		y++;
	}
}

void	calloc_failure(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	load_map(t_mapa *data)
{
	mapa_dimention_window(data);
	memory_map(data);
	upload_mapa(data);
}
