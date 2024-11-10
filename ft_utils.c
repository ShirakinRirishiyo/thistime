/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:48:48 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/10 11:12:27 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printear(unsigned int n)
{
	char *str;

	str = ft_itoa(n);
	if (str)
	{
		ft_printf("Número de pasos: %s\n", str);
		free(str);
	}
	else
	{
		ft_printf("Error al convertir el número de pasos.\n");
	}
}
//int exit_win(t_mapa *data);

int	exit_game(t_mapa *data)
{

	mlx_destroy_window(data->mlx, data->win);
	printf("--------------------------------------------------\n");
	printf("|              You gave up :(                    |\n");
	printf("|   Is the game hard for you? Try again......    |\n");
	printf("--------------------------------------------------\n");
	exit(EXIT_SUCCESS);
	free_game(data);
	exit (EXIT_FAILURE);
}


void	ft_game_result(t_mapa *data)
{
	int	x;
	int	y;
	mlx_clear_window(data->mlx, data->win);
	x = data->width * 40 / 2.4;
	y = data->height * 40 / 4;
	ft_printf("Dibujando resultado en (%d, %d)\n", x, y);
	mlx_put_image_to_window(data->mlx,
			data->win, data->imagenes->player_frame1, x, y);
}

void	actualizar_pantalla(t_mapa *data)
{
	mlx_clear_window(data->mlx, data->win);
	dibujo_mapa(data);
}

void	malloc_fail(void)
{
	perror("Memory allocation error");
	exit(EXIT_FAILURE);
}
