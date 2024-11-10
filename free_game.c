/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:09:14 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/10 09:25:16 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i++]);
	}
	free(array);
}

void free_game(t_mapa *data)
{
	printf( RED "ENTREEE AQUI" NC);
	mlx_destroy_image(data->mlx, data->imagenes->wall);
	mlx_destroy_image(data->mlx, data->imagenes->space);
	mlx_destroy_image(data->mlx, data->imagenes->player_frame1);
	mlx_destroy_image(data->mlx, data->imagenes->player_frame2);
	mlx_destroy_image(data->mlx, data->imagenes->collect);
	mlx_destroy_image(data->mlx, data->imagenes->exit);
	mlx_destroy_image(data->mlx, data->imagenes->fuego1);
	mlx_destroy_image(data->mlx, data->imagenes->fuego2);
	free(data->imagenes);
	
	free_array(data->map);
	free(data);
}
