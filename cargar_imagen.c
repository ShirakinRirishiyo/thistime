/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cargar_imagen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:20:08 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/11/07 12:33:13 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "so_long.h"

int	load_imagen(t_mapa *data, void **img, char *ruta)
{
	int	img_width;
	int	img_height;

	if (data == NULL || data->mlx == NULL)
	{
		fprintf(stderr, "Error: data o data->mlx es NULL.\n");
		return (1);
	}
	ft_printf("Cargando imagen desde: %s\n", ruta);
	*img = mlx_xpm_file_to_image(data->mlx, ruta, &img_width, &img_height);
	if (*img == NULL)
	{
		fprintf(stderr, "Error al cargar la imagen: %s\n", ruta);
		return (1);
	}
	ft_printf("Imagen cargada exitosamente.\n");
	return (0);
}

int	load_imagen_error(t_mapa *data, void **image, const char *image_path)
{
	if (load_imagen(data, image, image_path))
	{
		free_imagenes(data);
		return (1);
	}
	return (0);
}

int	load_imagenes(t_mapa *data)
{
	data->imagenes = (t_imagenes *)malloc(sizeof(t_imagenes));
	if (data->imagenes == NULL)
	{
		ft_printf("Error al asignar memoria para imágenes.\n");
		return (1);
	}
	if (imagen_error(data, (void **)&(data->imagenes->wall), WALL_IMAGE))
		return (1);
	if (imagen_error(data, (void **)&(data->imagenes->space), SPACE_IMAGE))
		return (1);
	if (imagen_error(data, (void **)&(data->imagenes->player_frame1), PLAYER))
		return (1);
	if (image_error(data, (void **)&(data->imagenes->collect), COLLECT1_IMAGE))
		return (1);
	if (image_error(data, (void **)&(data->imagenes->exit), EXIT_IMAGE))
		return (1);
	ft_printf("Todas las imágenes cargadas correctamente.\n");
	return (0);
}

int	call_function(t_mapa *data, char **argv)
{
	reset_data(data, argv[1]);
	check_general(data);
	return (EXIT_SUCCESS);
}

void	handle_error_fd(const char *mensaje, int fd, char *line)
{
	if (line != NULL)
		free(line);
	if (fd >= 0)
		close(fd);
	ft_printf("Error\n", mensaje);
	exit (EXIT_FAILURE);
}
