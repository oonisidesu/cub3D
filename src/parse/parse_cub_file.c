/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:48:34 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/10 18:11:27 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "get_next_line.h"
#include "init.h"
#include "libft.h"
#include "parse.h"
#include "utils.h"
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
	trimmed_line = ft_strtrim_r(line, WHITESPACE_CHARS);
	free(line);
	if (trimmed_line == NULL)
		print_error_free_exit("Failed to trimming\n", game);
	return (trimmed_line);
}

static void	process_file_lines(int fd, t_game *game, t_cub_el *cub_el_flag)
{
	char	*line;

	line = read_and_trim_line(fd, game);
	while (line != NULL)
	{
		if (!validate_line(line, game))
		{
			free(line);
			close(fd);
			print_error_free_exit("Invalid line in .cub file\n", game);
		}
		process_cub_line(line, game, cub_el_flag);
		free(line);
		line = read_and_trim_line(fd, game);
	}
	free(line);
	if (game->game_data.map.data != NULL)
		game->game_data.map.data[game->game_data.map.height] = NULL;
}

void	process_map(t_game *game)
{
	t_map	*map_data;
	size_t	i;
	size_t	j;
	char	**new_map;

	map_data = &game->game_data.map;
	map_data->height = get_map_max_height(map_data->data);
	map_data->width = get_map_max_width(map_data);
	new_map = allocate_map_memory(map_data->height, map_data->width);
	if (!new_map)
		print_error_free_exit("Failed to allocate memory for map\n", game);
	i = 0;
	while (i < (size_t)map_data->height)
	{
		j = 0;
		while (map_data->data[i][j] != '\0')
		{
			new_map[i][j] = (map_data->data[i][j] == ' ') ? '0' : map_data->data[i][j];
			j++;
		}
		while (j < (size_t)map_data->width)
		{
			new_map[i][j] = '0';
			j++;
		}
		i++;
	}
	free_array(map_data->data);
	map_data->data = new_map;
}

void	parse_cub_file(const char *filename, t_game *game)
{
	t_cub_el	cub_el_flag;
	int			fd;

	init_cub_el(&cub_el_flag);
	fd = open_cub_file(filename, game);
	process_file_lines(fd, game, &cub_el_flag);
	close(fd);
	process_map(game);
	display_map(&game->game_data.map);
	validate_cub_file(game, &cub_el_flag);
}
