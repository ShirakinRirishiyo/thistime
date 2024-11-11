/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:19:01 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 00:19:21 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_position(t_mapa *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'P')
			{
				data->start_i = i;
				data->start_j = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	count_coins(t_check *check, t_mapa *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'C')
			{
				check->coins_left++;
			}
			j++;
		}
		i++;
	}
}

void	find_exit(t_check *check, t_mapa *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'E')
			{
				check->exit_x = i;
				check->exit_y = j;
				check->exitparse = 1;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_position(t_check *check, t_mapa *data)
{
	find_player_position(data);
	count_coins(check, data);
	find_exit(check, data);
}
