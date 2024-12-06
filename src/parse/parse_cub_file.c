/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:48:34 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/06 17:36:35 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "init.h"
#include "libft.h"
#include "parse.h"
#include "util.h"
#include "validate.h"
#include <fcntl.h>

static int	open_cub_file(const char *filename, t_game *game)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error_free_exit("Failed to open file\n", game);
	return (fd);
}

static char	*read_and_trim_line(int fd, t_game *game)
{
	char	*line;
	char	*trimmed_line;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	trimmed_line = ft_strtrim(line, WHITESPACE_CHARS);
	free(line);
	if (trimmed_line == NULL)
		print_error_free_exit("Failed to allocate memory during trimming\n",
			game);
	return (trimmed_line);
}

static void	process_file_lines(int fd, t_game *game, t_cub_el *cub_el_flag)
{
	char	*line;

	line = read_and_trim_line(fd, game);
	while (line != NULL)
	{
		if (!validate_and_save_line(line, game))
		{
			free(line);
			close(fd);
			print_error_free_exit("Invalid line in .cub file\n", game);
		}
		process_cub_line(line, game, cub_el_flag);
		free(line);
		line = read_and_trim_line(fd, game);
	}
}

bool	is_texture_line(const char *line)
{
	if (is_prefix_and_whitespace(line, "NO", WHITESPACE_CHARS))
		return (true);
	if (is_prefix_and_whitespace(line, "SO", WHITESPACE_CHARS))
		return (true);
	if (is_prefix_and_whitespace(line, "WE", WHITESPACE_CHARS))
		return (true);
	if (is_prefix_and_whitespace(line, "EA", WHITESPACE_CHARS))
		return (true);
	return (false);
}

void	parse_cub_file(const char *filename, t_game *game)
{
	t_cub_el	cub_el_flag;
	int			fd;

	init_cub_el(&cub_el_flag);
	fd = open_cub_file(filename, game);
	process_file_lines(fd, game, &cub_el_flag);
	close(fd);
	validate_cub_file(game, &cub_el_flag);
}
