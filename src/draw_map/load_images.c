/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:13:01 by heidi             #+#    #+#             */
/*   Updated: 2026/07/09 02:39:48 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "graphics.h"

static int	load_texture(t_game *game, t_img *img, char *path, char *name)
{
	int	width;
	int	height;

	img->img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!img->img)
		return (printf("Error\nFailed to load %s texture\n", name), 1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (printf("Error\nFailed to access %s texture data\n", name), 1);
	return (0);
}

int	load_images(t_game *game)
{
	if (load_texture(game, &game->north, game->config.north, "north"))
		return (1);
	if (load_texture(game, &game->south, game->config.south, "south"))
		return (1);
	if (load_texture(game, &game->east, game->config.east, "east"))
		return (1);
	if (load_texture(game, &game->west, game->config.west, "west"))
		return (1);
	return (0);
}
