/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:20:59 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/09/11 16:11:22 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_element(t_contxt *ctx, void *img, int x, int y)
{
	if (mlx_put_image_to_window(ctx->mlx, ctx->win, img,
			x * SPRITE_SIZE, y * SPRITE_SIZE) != 0)
	{
		ft_printf("Error al dibujar en (%d, %d)\n", y, x);
	}
	else
	{
		ft_printf("Dibujando en (%d, %d) con imagen: %p\n", x, y, img);
	}
}

void	draw_map_element(t_contxt *ctx, t_mapa *data, int i, int j)
{
	if (data->map[i][j] == '1')
		draw_element(ctx, ctx->imagenes->wall, j, i);
	else if (data->map[i][j] == '0')
		draw_element(ctx, ctx->imagenes->space, j, i);
	else if (data->map[i][j] == 'P')
		draw_element(ctx, ctx->imagenes->player_frame1, j, i);
	else if (data->map[i][j] == 'C')
	{
		draw_element(ctx, ctx->imagenes->collect, j, i);
		if (data->x == j && data->y == i)
		{
			data->map[i][j] = '0';
			data->colectables--;
		}
	}
	else if (data->map[i][j] == 'E')
	{
		ft_printf("Dibujando salida en (%d, %d)\n", i, j);
		draw_element(ctx, ctx->imagenes->exit, j, i);
	}
	else
		ft_printf("Error\n: Wron character");
}

void	draw_map(t_mapa *data)
{
	int			i;
	int			j;
	t_contxt	ctx;

	if (data == NULL || data->map == NULL || data->imagenes == NULL)
	{
		ft_printf("Error: Datos no inicializados.\n");
		return ;
	}
	ctx.mlx = data->mlx;
	ctx.win = data->win;
	ctx.imagenes = data->imagenes;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			draw_map_element(&ctx, data, i, j);
			j++;
		}
		i++;
	}
	ft_printf("Coordenadas del jugador --> (%d, %d)\n", data->x, data->y);
}
