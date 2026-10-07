/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vildan <vildan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 22:02:00 by vildan            #+#    #+#             */
/*   Updated: 2026/07/03 22:02:00 by vildan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	set_player(t_player *player, int x, int y, char dir)
{
	player->player_x = x;
	player->player_y = y;
	player->start_dir = dir;
	player->is_set = true;
}

static int	check_player_cell(t_parser *parser, int x, int y, int *count)
{
	char	cell;

	cell = parser->map.map_rows[y][x];
	if (!is_player_char(cell))
		return (0);
	(*count)++;
	if (*count > 1)
		return (printf("Error\nMore than one player found\n"), 1);
	set_player(&parser->player, x, y, cell);
	return (0);
}

static int	scan_map_rows(t_parser *parser, int *count)
{
	int	y;
	int	x;

	y = 0;
	while (parser->map.map_rows[y])
	{
		x = 0;
		while (parser->map.map_rows[y][x])
		{
			if (check_player_cell(parser, x, y, count))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	find_player(t_parser *parser)
{
	int	player_count;

	player_count = 0;
	if (scan_map_rows(parser, &player_count))
		return (1);
	if (player_count == 0)
		return (printf("Error\nPlayer is missing\n"), 1);
	return (validate_map_closed(parser));
}
