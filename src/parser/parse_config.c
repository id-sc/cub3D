/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vildan <vildan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 20:24:36 by vildan            #+#    #+#             */
/*   Updated: 2026/07/03 20:31:45 by vildan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_texture(char **texture_path, char *value)
{
	char	*trimmed_path;
	int		fd;
	int		len;

	trimmed_path = ft_strtrim(value, " ");
	len = ft_strlen(trimmed_path);
	if (*texture_path || !*trimmed_path || len < 4 || ft_strncmp(trimmed_path
			+ len - 4, ".xpm", 4))
		return (free(trimmed_path), printf("Error\nInvalid texture path\n"), 1);
	fd = open(trimmed_path, O_RDONLY);
	if (fd < 0)
		return (free(trimmed_path),
			printf("Error\nCould not open texture file\n"), 1);
	close(fd);
	*texture_path = trimmed_path;
	return (0);
}

static int	parse_status(int parse_result)
{
	if (parse_result)
		return (-1);
	return (1);
}

static int	parse_color(t_color *color, char *value)
{
	char	**rgb;

	rgb = ft_split(value, ',');
	if (color->is_set || !rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (free_str_array(rgb), printf("Error\nInvalid color format\n"),
			1);
	if (!is_valid_rgb_value(rgb[0]) || !is_valid_rgb_value(rgb[1])
		|| !is_valid_rgb_value(rgb[2]))
		return (free_str_array(rgb), printf("Error\nInvalid color format\n"),
			1);
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	free_str_array(rgb);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
		return (printf("Error\nColor out of range\n"), 1);
	color->hex = (color->r << 16) | (color->g << 8) | color->b;
	color->is_set = true;
	return (0);
}

static int	parse_config_line(t_parser *parser, char *line)
{
	while (*line == ' ')
		line++;
	if (!ft_strncmp(line, "NO ", 3))
		return (parse_status(parse_texture(&parser->config.north, line + 3)));
	if (!ft_strncmp(line, "SO ", 3))
		return (parse_status(parse_texture(&parser->config.south, line + 3)));
	if (!ft_strncmp(line, "WE ", 3))
		return (parse_status(parse_texture(&parser->config.west, line + 3)));
	if (!ft_strncmp(line, "EA ", 3))
		return (parse_status(parse_texture(&parser->config.east, line + 3)));
	if (!ft_strncmp(line, "F ", 2))
		return (parse_status(parse_color(&parser->config.floor, line + 2)));
	if (!ft_strncmp(line, "C ", 2))
		return (parse_status(parse_color(&parser->config.ceiling, line + 2)));
	return (0);
}

int	parse_config(t_parser *parser)
{
	int	i;
	int	line_status;
	int	map_started;

	i = 0;
	map_started = 0;
	while (parser->lines[i])
	{
		line_status = parse_config_line(parser, parser->lines[i]);
		if (line_status < 0)
			return (1);
		if (map_started && line_status > 0)
			return (printf("Error\nConfig elements must come before the map\n"),
				1);
		if (!line_status && !is_map_line(parser->lines[i]))
			return (printf("Error\nInvalid line in file\n"), 1);
		if (!line_status && is_map_line(parser->lines[i]))
			map_started = 1;
		i++;
	}
	if (!parser->config.north || !parser->config.south || !parser->config.west
		|| !parser->config.east || !parser->config.floor.is_set
		|| !parser->config.ceiling.is_set)
		return (printf("Error\nMissing one or more config elements\n"), 1);
	return (parse_map(parser));
}
