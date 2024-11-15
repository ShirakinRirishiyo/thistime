/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:48:41 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/07/29 14:48:41 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	frame_s(t_mapa *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	if (data->colectables == 0 && data->player == 1 && data->finish == 1)
	{
		ft_printf("El juego ha terminado: llamando a ft_game_result\n");
		ft_game_result(data);
	}
	return (0);
}

void	check_general(t_mapa *data)
{
	t_check	*check;

	ft_printf("Verificando el mapa...\n");
	comprobacion_open_ber(data);
	ft_printf("comprobacionhecha\n");
	maps_objects(data);
	check = inicializar_check(data->height, data->width);
	find_position(check, data);
	if (ft_accesibility(data) == 0)
	{
		ft_printf("Error\n: Invalid map\n Fail to reach colectables o exit\n");
		free_check(check, data->height);
		exit (EXIT_FAILURE);
	}
	free_check(check, data->height);
}

void	reset_data(t_mapa *data, char *name)
{
	data->text = name;
}

void	handle_error(const char *mensaje)
{
	fprintf(stderr, "%s\n", mensaje);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_mapa	*data;

	if (argc != 2)
	{
		ft_printf("Uso: %s <nombre.ber>\n", argv[0]);
		return (1);
	}
	data = (t_mapa *)malloc(sizeof(t_mapa));
	if (data == NULL)
		handle_error("Fail\n");
	data = (t_mapa *)memset(data, 0, sizeof(t_mapa));
	data->mlx = mlx_init();
	data->text = argv[1];
	load_map(data);
	ft_check_borders(data);
	call_function(data, argv);
	load_imagenes(data);
	data->win = mlx_new_window(data->mlx, data->width * 64,
			data->height * 64, "so_long");
	mlx_hook(data->win, 17, 0, exit_game, (void *)data);
	mlx_key_hook(data->win, key_hook, (void *)data);
	frame_s(data);
	mlx_loop(data->mlx);
	free_game(data);
	return (0);
}
