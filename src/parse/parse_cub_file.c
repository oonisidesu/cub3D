/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:48:34 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/28 15:34:22 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "parse.h"
#include <fcntl.h>

int	open_cub_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror("Error opening file");
	return (fd);
}

void	process_cub_line(const char *line, t_cub3d *game)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, "\n");
	if (!trimmed)
		return ;
	if (ft_strncmp(trimmed, "NO ", 3) == 0 || ft_strncmp(trimmed, "SO ", 3) == 0
		|| ft_strncmp(trimmed, "WE ", 3) == 0 || ft_strncmp(trimmed, "EA ",
			3) == 0)
	{
		parse_texture_line(trimmed, &game->textures);
	}
	else if (ft_strncmp(trimmed, "F ", 2) == 0)
	{
		parse_color_line(trimmed + 2, game->colors.floor);
	}
	else if (ft_strncmp(trimmed, "C ", 2) == 0)
	{
		parse_color_line(trimmed + 2, game->colors.ceiling);
	}
	else if (ft_strlen(trimmed) > 0)
	{
		parse_map_line(trimmed, &game->map);
	}
	free(trimmed);
}

void	parse_cub_file(const char *filename, t_cub3d *game)
{
	int		fd;
	char	*line;

	fd = open_cub_file(filename);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line != NULL)
	{
		process_cub_line(line, game);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
