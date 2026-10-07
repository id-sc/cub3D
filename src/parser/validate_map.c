/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vildan <vildan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:40:00 by vildan            #+#    #+#             */
/*   Updated: 2026/07/05 22:40:00 by vildan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_walkable(char cell)
{
	return (cell == '0' || cell == 'N' || cell == 'S' || cell == 'E'
		|| cell == 'W');
}

static int	cell_is_open(t_map *map, int row, int col)
{
	if (row < 0 || col < 0 || row >= map->height)
		return (1);
	if (col >= (int)ft_strlen(map->map_rows[row]))
		return (1);
	if (map->map_rows[row][col] == ' ')
		return (1);
	return (0);
}

static int	check_map_cell(t_map *map, int row, int col)
{
	char	cell;

	cell = map->map_rows[row][col];
	if (!is_walkable(cell))
		return (0);
	if (cell_is_open(map, row - 1, col) || cell_is_open(map, row + 1, col)
		|| cell_is_open(map, row, col - 1) || cell_is_open(map, row, col + 1))
		return (printf("Error\nMap is not closed\n"), 1);
	return (0);
}

int	validate_map_closed(t_parser *parser)
{
	int	row;
	int	col;

	row = 0;
	while (parser->map.map_rows[row])
	{
		col = 0;
		while (parser->map.map_rows[row][col])
		{
			if (check_map_cell(&parser->map, row, col))
				return (1);
			col++;
		}
		row++;
	}
	return (0);
}
