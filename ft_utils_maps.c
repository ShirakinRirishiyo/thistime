/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:49:45 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/11 02:09:48 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapa_dimention_window(t_mapa *data)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(data->text, O_RDONLY);
	if (fd == -1)
		handle_error("Error al abrir el archivo");
	data->height = 0;
	data->width = 0;
	line = get_next_line(fd);
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
		handle_error("Error: El mapa está vacío.");
}

void	memory_map(t_mapa *data)
{
	data->map = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (data->map == NULL)
		handle_error("Error al asignar memoria para el mapa");
}

void	upload_mapa(t_mapa *data)
{
	int		fd;
	int		i;
	int		len;
	char	*line;

	fd = open(data->text, O_RDONLY);
	if (fd == -1)
		handle_error("Error al abrir el archivo");
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		data->map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
	close(fd);
}
