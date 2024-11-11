/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_for_other.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:22:40 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 00:26:14 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_and_free(void *check, int height)
{
	ft_printf("Player has access to collectables and exit.\n");
	free_check(check, height);
	return (1);
}

void	count_objects(t_mapa *data, t_indices *indices)
{
	indices->j = 0;
	indices->end = 0;
	while (data->map[++indices->j])
	{
		indices->i = 0;
		while (data->map[indices->j][++indices->i])
		{
			if (data->map[indices->j][indices->i] == 'P')
			{
				data->x = indices->i;
				data->y = indices->j;
				data->player++;
			}
			else if (data->map[indices->j][indices->i] == 'C')
				data->colectables++;
			else if (data->map[indices->j][indices->i] == 'E')
				indices->end++;
		}
	}
}

void	validate_map(t_mapa *data, t_indices *indices)
{
	if (data->player != 1 || data->colectables < 1 || indices->end != 1)
	{
		ft_printf ("Error aca\n");
		exit (EXIT_FAILURE);
	}
}
