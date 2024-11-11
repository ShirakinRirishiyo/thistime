/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_practical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:51:07 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/07/17 20:51:07 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_check	*inicializar_check(int height, int width)
{
	int		i;
	t_check	*check;

	check = malloc(sizeof(t_check));
	check->maps = malloc(height * sizeof(int *));
	i = 0;
	while (i < height)
	{
		check->maps[i] = ft_calloc(width, sizeof(int));
		i++;
	}
	check->coins_left = 0;
	check->exitparse = 0;
	return (check);
}

void	free_check(t_check *check, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(check->maps[i]);
		i++;
	}
	free(check->maps);
	free(check);
}


void	flood_fill(int x, int y, t_check *check, t_mapa *data)
{
	check->maps[x][y] = 1;
	if (data->map[x][y] == 'C')
		check->coins_left--;
	if (is_valid(x, y - 1, check, data))
		flood_fill(x, y - 1, check, data);
	if (is_valid(x, y + 1, check, data))
		flood_fill(x, y + 1, check, data);
	if (is_valid(x - 1, y, check, data))
		flood_fill(x - 1, y, check, data);
	if (is_valid(x + 1, y, check, data))
		flood_fill(x + 1, y, check, data);
}

int	ft_accesibility(t_mapa *data)
{
	t_check	*check;
	int		access_colectables;
	int		access_exit;

	check = inicializar_check(data->height, data->width);
	find_position(check, data);
	if (check->exitparse == 0)
	return print_and_free(check, data->height);
	flood_fill(data->start_i, data->start_j, check, data);
	access_colectables = way_to_collect(check);
	access_exit = way_to_exit(check);
	if (access_colectables == 1 && access_exit == 1)
	return print_and_free(check, data->height);
	else
	{
		if (access_colectables== 0)
			ft_printf("Error\n: No access to all collectables.\n");
		if (access_exit == 0)
			ft_printf("Error\n: No access to exit.\n");
		free_check(check, data->height);
		return (0);
	}
}
