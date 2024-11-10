/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:56:31 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/07/29 13:56:31 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(t_mapa *data, int move_x, int move_y)
{
	if (data->map[data->y + move_y][data->x + move_x] == '1')
	{
		ft_printf("Error\n. Movement blocked");
		return ;
	}
	if (data->map[data->y + move_y][data->x + move_x] == 'C'
			|| data->map[data->y + move_y][data->x + move_x] == '0')
	{
		if (data->map[data->y + move_y][data->x + move_x] == 'C')
			data->colectables--;
		data->map[data->y][data->x] = '0';
		data->map[data->y + move_y][data->x + move_x] = 'P';
		data->y += move_y;
		data->x += move_x;
		data->pasos++;
	}
	else if (data->map[data->y + move_y][data->x + move_x] == 'E'
			&& data->colectables == 0)
	{
		exit_game(data);
	}
	refresh_window(data);
}

int	key_hook(int keycode, void *param)
{
	t_mapa	*data;

	data = (t_mapa *)param;
	if (keycode == ESC)
		exit_game(data);
	else if (keycode == W)
	{
		ft_printf("Moviendo hacia arriba\n");
		movement(data, 0, -1);
	}
	else if (keycode == A)
	{
		ft_printf("Moviendo hacia la izquierda\n");
		movement(data, -1, 0);
	}
	else if (keycode == S)
	{
		movement(data, 0, 1);
	}
	else if (keycode == D)
	{
		ft_printf("Moviendo hacia la derecha\n");
		movement(data, 1, 0);
	}
	return (0);
}
