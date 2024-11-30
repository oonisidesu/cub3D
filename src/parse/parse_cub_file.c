/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:48:34 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/30 16:21:07 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "parse.h"
#include "util.h"
#include <fcntl.h>

int	open_cub_file(const char *filename, t_game *game)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error_free_exit("Failed to open file\n", game);
	return (fd);
}

bool	is_texture_line(const char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (true);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (true);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (true);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (true);
	return (false);
}

void	process_cub_line(const char *line, t_game *game)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, "\n");
	if (!trimmed)
		print_error_free_exit("Failed to parse line\n", game);
	if (is_texture_line(trimmed))
	{
		if (parse_texture_line(trimmed, &game->game_data.textures) == false)
			print_error_free_exit("Failed to parse texture line\n", game);
	}
	else if (ft_strncmp(trimmed, "F ", 2) == 0)
	{
		parse_color_line(trimmed + 2, game->game_data.colors.floor);
	}
	else if (ft_strncmp(trimmed, "C ", 2) == 0)
	{
		parse_color_line(trimmed + 2, game->game_data.colors.ceiling);
	}
	else if (ft_strlen(trimmed) > 0)
	{
		parse_map_line(trimmed, &game->game_data.map);
	}
	free(trimmed);
}

void	parse_cub_file(const char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open_cub_file(filename, game);
	line = get_next_line(fd);
	while (line != NULL)
	{
		// if (!validate_and_save_line(line, game))
		// {
		// 	free(line);
		// 	close(fd);
		// 	print_error_free_exit("Invalid line in .cub file\n", game);
		// }
		process_cub_line(line, game);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	// if (!validate_map(game->game_data.map))
	// 	print_error_free_exit("Invalid map\n", game);
}
