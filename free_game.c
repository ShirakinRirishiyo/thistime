/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:09:14 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/10 12:51:58 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i++]);
	}
	free(array);
}

void	free_game(t_mapa *data)
{
	ft_printf(RED "ENTREEE AQUI" NC);
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

void	free_imagenes(t_mapa *data)
{
	if (data->imagenes->wall)
		mlx_destroy_image(data->mlx, data->imagenes->wall);
	if (data->imagenes->space)
		mlx_destroy_image(data->mlx, data->imagenes->space);
	if (data->imagenes->player_frame1)
		mlx_destroy_image(data->mlx, data->imagenes->player_frame1);
	if (data->imagenes->collect)
		mlx_destroy_image(data->mlx, data->imagenes->collect);
	if (data->imagenes->exit)
		mlx_destroy_image(data->mlx, data->imagenes->exit);
	free(data->imagenes);
}

void	free_map(t_mapa *data)
{
	int	i;

	i = 0;
	while (data->map && data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	free_double_p(t_mapa *data)
{
	int	i;

	while (i < data->height)
	{
		free(data->map[i])
		i++;
	}
	free(data->map);
}
