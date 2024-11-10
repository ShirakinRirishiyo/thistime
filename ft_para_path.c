/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_para_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:14:53 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/10 04:31:41 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	camino_hacia_coleccionables(t_check *check)
{
	return (check->coins_left == 0);
}

int	camino_hacia_salida(t_check *check)
{
    return (check->maps[check->exit_x][check->exit_y] == 1);
}

int	es_valido(int x, int y, t_check *check, t_mapa *data)
{
	if (x >= 0 && x < data->height && y >= 0 && y < data->width &&
			data->map[x][y] != '1' && check->maps[x][y] == 0)
	{
		return (1);
	}
	return (0);
}

void	ft_input_error(int	argc)
/* only exists because of the 25 line limit */
{
	if (argc != 2)
	{
		manejar_error("Error\nUsage: './so_long mappath/mapname.ber'\n");
		exit(EXIT_FAILURE);
	}
}
