/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesainte <hesainte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 21:18:00 by vildan            #+#    #+#             */
/*   Updated: 2026/07/09 18:37:18 by hesainte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	find_map_start(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (is_map_line(lines[i]))
			return (i);
		i++;
	}
	return (-1);
}

static int	copy_map_rows(t_map *map, char **lines, int start)
{
	int	i;

	map->map_rows = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map_rows)
		return (1);
	i = 0;
	while (i < map->height)
	{
		map->map_rows[i] = ft_strdup(lines[start + i]);
		if (!map->map_rows[i])
		{
			map->map_rows[i] = NULL;
			free_str_array(map->map_rows);
			map->map_rows = NULL;
			return (1);
		}
		i++;
	}
	map->map_rows[i] = NULL;
	return (0);
}

static void	set_map_width(t_map *map)
{
	int	i;
	int	row_len;

	i = 0;
	map->width = 0;
	while (map->map_rows[i])
	{
		row_len = ft_strlen(map->map_rows[i]);
		if (row_len > map->width)
			map->width = row_len;
		i++;
	}
}

int	parse_map(t_parser *parser)
{
	int	map_start;

	map_start = find_map_start(parser->lines);
	if (map_start < 0)
		return (printf("Error\nMap is missing\n"), 1);
	parser->map.height = 0;
	while (parser->lines[map_start + parser->map.height])
		parser->map.height++;
	if (copy_map_rows(&parser->map, parser->lines, map_start))
		return (printf("Error\nCould not save map\n"), 1);
	set_map_width(&parser->map);
	return (find_player(parser));
}
