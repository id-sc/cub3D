/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 02:19:22 by hesainte          #+#    #+#             */
/*   Updated: 2026/07/09 19:18:01 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "graphics_bonus.h"
#include "libft.h"

/* Copy the parsed data into the render struct instead of overwriting it. */
/* This keeps the renderer data aligned with the parser output. */
void	init_game_from_parser(t_game *game, t_parser *parser)
{
	game->parser = *parser;
	game->map = game->parser.map;
	game->config = game->parser.config;
	game->player = game->parser.player;
	ft_bzero(parser, sizeof(t_parser));
}

/*
** Bigger window but less smooth:
** game->win_w = screen_w;
** game->win_h = screen_h;
** if (game->win_w < 640) game->win_w = 640;
** if (game->win_h < 480) game->win_h = 480;
** Current option: smaller but more smooth.
*/
void	init_game(t_game *game)
{
	int	screen_w;
	int	screen_h;

	mlx_get_screen_size(game->mlx, &screen_w, &screen_h);
	game->win_w = game->map.width * 64;
	game->win_h = game->map.height * 64;
	if (game->win_w > screen_w)
		game->win_w = screen_w;
	if (game->win_h > screen_h)
		game->win_h = screen_h;
}
