/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vildan <vildan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 20:24:45 by vildan            #+#    #+#             */
/*   Updated: 2026/07/03 20:24:46 by vildan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

static char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	if (!joined)
	{
		free(s1);
		return (NULL);
	}
	free(s1);
	return (joined);
}

static char	*read_file_content(int fd)
{
	char	buffer[1025];
	char	*content;
	ssize_t	bytes_read;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	bytes_read = read(fd, buffer, 1024);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		content = ft_strjoin_and_free(content, buffer);
		if (!content)
			return (NULL);
		bytes_read = read(fd, buffer, 1024);
	}
	if (bytes_read < 0)
		return (free(content), NULL);
	return (content);
}

int	read_cub_file(t_parser *parser, char *file_path)
{
	int		fd;
	char	*content;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCould not open file: %s\n", file_path);
		return (1);
	}
	content = read_file_content(fd);
	close(fd);
	if (!content)
	{
		printf("Error\nCould not read file: %s\n", file_path);
		return (1);
	}
	parser->file_path = file_path;
	parser->lines = ft_split(content, '\n');
	free(content);
	if (!parser->lines)
	{
		printf("Error\nCould not split file content\n");
		return (1);
	}
	return (0);
}
