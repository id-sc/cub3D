/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_init_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vildan <vildan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 00:00:00 by vildan            #+#    #+#             */
/*   Updated: 2026/07/10 00:00:00 by vildan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics_bonus.h"
#include "player_bonus.h"

static int	graphics_error(t_game *game, char *message)
{
	printf("Error\n%s\n", message);
	free_game(game);
	return (1);
}

static int	create_render_surface(t_game *game)
{
	game->window = mlx_new_window(game->mlx, game->win_w, game->win_h,
			"cube3D");
	if (!game->window)
		return (graphics_error(game, "Failed to create window"));
	game->image.img = mlx_new_image(game->mlx, game->win_w, game->win_h);
	if (!game->image.img)
		return (graphics_error(game, "Failed to create render image"));
	game->image.addr = mlx_get_data_addr(game->image.img,
			&game->image.bits_per_pixel, &game->image.line_length,
			&game->image.endian);
	if (!game->image.addr)
		return (graphics_error(game, "Failed to access render image data"));
	return (0);
}

int	start_graphics(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (graphics_error(game, "Failed to initialize MiniLibX"));
	init_game(game);
	if (create_render_surface(game))
		return (1);
	if (load_images(game))
		return (free_game(game), 1);
	init_player(game);
	mlx_hook(game->window, 2, 1L << 0, (void *)key_press, game);
	mlx_hook(game->window, 3, 1L << 1, (void *)key_release, game);
	mlx_hook(game->window, 17, 1L << 0, (void *)close_win, game);
	mlx_loop_hook(game->mlx, (void *)render_frame, game);
	mlx_loop(game->mlx);
	return (free_game(game), 0);
}
