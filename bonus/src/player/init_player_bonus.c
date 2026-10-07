/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:15:52 by heidi             #+#    #+#             */
/*   Updated: 2026/07/09 02:46:08 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "player_bonus.h"

void	init_player(t_game *game)
{
	game->player.player_x += 0.5;
	game->player.player_y += 0.5;
	game->player.dir_x = 0.00;
	game->player.dir_y = 0.00;
	game->player.plane_x = 0.00;
	game->player.plane_y = 0.00;
	init_player_direction(&game->player);
}

void	init_player_direction(t_player *player)
{
	if (player->start_dir == 'N')
	{
		player->dir_y = -1.00;
		player->plane_x = 0.66;
	}
	else if (player->start_dir == 'S')
	{
		player->dir_y = 1.00;
		player->plane_x = -0.66;
	}
	else if (player->start_dir == 'E')
	{
		player->dir_x = 1.00;
		player->plane_y = 0.66;
	}
	else if (player->start_dir == 'W')
	{
		player->dir_x = -1.00;
		player->plane_y = -0.66;
	}
}
