/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 01:08:19 by hesainte          #+#    #+#             */
/*   Updated: 2026/07/09 02:46:59 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	rotate_player(t_player *p, float angle)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}

void	update_player_key_w(t_game *game)
{
	float	nx;
	float	ny;

	nx = game->player.player_x + game->player.dir_x * SPEED;
	ny = game->player.player_y + game->player.dir_y * SPEED;
	if (!is_wall(game, nx, game->player.player_y))
		game->player.player_x = nx;
	if (!is_wall(game, game->player.player_x, ny))
		game->player.player_y = ny;
}

void	update_player_key_s(t_game *game)
{
	float	nx;
	float	ny;

	nx = game->player.player_x - game->player.dir_x * SPEED;
	ny = game->player.player_y - game->player.dir_y * SPEED;
	if (!is_wall(game, nx, game->player.player_y))
		game->player.player_x = nx;
	if (!is_wall(game, game->player.player_x, ny))
		game->player.player_y = ny;
}

void	update_player_key_a(t_game *game)
{
	float	nx;
	float	ny;

	nx = game->player.player_x - game->player.plane_x * SPEED;
	ny = game->player.player_y - game->player.plane_y * SPEED;
	if (!is_wall(game, nx, game->player.player_y))
		game->player.player_x = nx;
	if (!is_wall(game, game->player.player_x, ny))
		game->player.player_y = ny;
}

void	update_player_key_d(t_game *game)
{
	float	nx;
	float	ny;

	nx = game->player.player_x + game->player.plane_x * SPEED;
	ny = game->player.player_y + game->player.plane_y * SPEED;
	if (!is_wall(game, nx, game->player.player_y))
		game->player.player_x = nx;
	if (!is_wall(game, game->player.player_x, ny))
		game->player.player_y = ny;
}
