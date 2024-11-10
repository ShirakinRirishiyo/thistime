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

void	dibujar_elemento(t_contxt *ctx, void *img, int x, int y)
{
    if (mlx_put_image_to_window(ctx->mlx, ctx->win, img,
            x * SPRITE_SIZE, y * SPRITE_SIZE) != 0)
    {
        ft_printf("Error al dibujar en (%d, %d)\n", y, x);
    }
    else {
        ft_printf("Dibujando en (%d, %d) con imagen: %p\n", x, y, img);
    }
}

void dibujar_elemento_del_mapa(t_contxt *ctx, t_mapa *data, int i, int j)
{
    ft_printf("Procesando celda en (%d, %d): '%c'\n", i, j, data->map[i][j]);

    if (data->map[i][j] == '1') {
        ft_printf("Dibujando pared en (%d, %d)\n", i, j);
        dibujar_elemento(ctx, ctx->imagenes->wall, j, i);
    } 
    else if (data->map[i][j] == '0') {
        ft_printf("Dibujando espacio vacío en (%d, %d)\n", i, j);
        dibujar_elemento(ctx, ctx->imagenes->space, j, i);
    } 
    else if (data->map[i][j] == 'P') {
        ft_printf("Dibujando jugador en (%d, %d)\n", i, j);
        dibujar_elemento(ctx, ctx->imagenes->player_frame1, j, i);
    } 
    else if (data->map[i][j] == 'C') {
        ft_printf("Dibujando coleccionable en (%d, %d)\n", i, j);
        dibujar_elemento(ctx, ctx->imagenes->collect, j, i);
        
        // Si el jugador está en esta posición, lo recoge
        if (data->x == j && data->y == i) {
            printf("¡Coleccionable recogido! (%d, %d)\n", j, i);
            data->map[i][j] = '0';  // Marca la posición como vacía
            data->colectables--;  // Disminuye el contador de coleccionables
        }
    } 
    else if (data->map[i][j] == 'E') {
        ft_printf("Dibujando salida en (%d, %d)\n", i, j);
        dibujar_elemento(ctx, ctx->imagenes->exit, j, i);
    } 
    else {
        ft_printf("Error: Carácter no válido '%c' en (%d, %d)\n", data->map[i][j], i, j);
    }
}

void	dibujo_mapa(t_mapa *data)
{
    int			i;
    int			j;
    t_contxt	ctx;

    if (data == NULL || data->map == NULL || data->imagenes == NULL)
    {
        ft_printf("Error: Datos no inicializados.\n");
        return ;
    }

    // Configurar el contexto
    ctx.mlx = data->mlx;
    ctx.win = data->win;
    ctx.imagenes = data->imagenes;

    i = 0;
    while (data->map[i])  // Iterar por cada fila del mapa
    {
        j = 0;
        while (data->map[i][j])  // Iterar por cada columna en la fila
        {
            ft_printf("Dibujando celda en (%d, %d): '%c'\n", i, j, data->map[i][j]);
            dibujar_elemento_del_mapa(&ctx, data, i, j);
            j++;
        }
        i++;
    }
    
    // Confirmar las coordenadas del jugador
    ft_printf("Coordenadas del jugador --> (%d, %d)\n", data->x, data->y);
}
