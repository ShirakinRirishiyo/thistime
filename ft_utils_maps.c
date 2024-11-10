/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:49:45 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/10 12:53:01 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	obtener_dimensiones_y_validar(t_mapa *data)
{
	int		fd;
	int		len;
	char	*line;

	line = get_next_line(fd);
	fd = open(data->text, O_RDONLY);
	if (fd == -1)
		manejar_error("Error al abrir el archivo");
	data->height = 0;
	data->width = 0;
	while (get_next_line(fd) != NULL)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (len > data->width)
			data->width = len - 1;
		data->height++;
		free(line);
	}
	close(fd);
	if (data->height == 0 || data->width == 0)
		manejar_error("Error: El mapa está vacío.");
	if (data->height > MAX_MAP_HEIGHT || data->width > MAX_MAP_WIDTH)
		manejar_error("Error: El mapa es demasiado grande.");
}

void	asignar_memoria_mapa(t_mapa *data)
{
	data->map = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (data->map == NULL)
		manejar_error("Error al asignar memoria para el mapa");
}

void	upload_mapa(t_mapa *data)
{
	int		fd;
	int		i;
	int		len;
	char	*line;

	line = get_next_line(fd);
	fd = open(data->text, O_RDONLY);
	if (fd == -1)
		manejar_error("Error al abrir el archivo");
	i = 0;
	while (get_next_line(fd) != NULL)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		data->map[i++] = ft_strdup(line);
		free(line);
	}
	data->map[i] = NULL;
	close(fd);
}
