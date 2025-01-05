/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:48:34 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2025/01/05 11:59:20 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "init.h"
#include "libft.h"
#include "parse.h"
#include "utils.h"
#include "validate.h"
#include <fcntl.h>

static void	process_file_lines(t_game *game, t_cub_el *cub_el_flag)
{
	char	**line;

	line = &game->game_data.map.parse.line;
	*line = read_and_trim_line(game->game_data.map.parse.fd);
	while (*line != NULL)
	{
		validate_line(*line, game, cub_el_flag);
		process_cub_line(*line, game, cub_el_flag);
		free(*line);
		*line = read_and_trim_line(game->game_data.map.parse.fd);
	}
	free(*line);
}

static void	normalize_map_line(char **new_map, char *line, size_t width,
		size_t row)
{
	size_t	j;

	if (!new_map || !new_map[row] || !line)
		return ;
	j = 0;
	while (line[j] && j < width)
	{
		if (ft_strchr(WHITESPACE_CHARS, line[j]))
			new_map[row][j] = '0';
		else
			new_map[row][j] = line[j];
		j++;
	}
	while (j < width)
	{
		new_map[row][j] = '0';
		j++;
	}
}

static void	process_map(t_game *game)
{
	t_map	*map_data;
	char	**new_map;
	size_t	i;

	map_data = &game->game_data.map;
	if (!map_data->data)
		print_error_free_exit("Failed to read map\n", game);
	map_data->height = get_map_max_height(map_data->data);
	map_data->width = get_map_max_width(map_data);
	new_map = allocate_map_memory(map_data->height, map_data->width);
	if (!new_map)
		print_error_free_exit("Failed to allocate memory for map\n", game);
	i = 0;
	while (i < map_data->height)
	{
		normalize_map_line(new_map, map_data->data[i], map_data->width, i);
		i++;
	}
	free_array(map_data->data);
	map_data->data = new_map;
}

void	parse_cub_file(const char *filename, t_game *game)
{
	t_cub_el	cub_el_flag;
	int			*fd;

	fd = &game->game_data.map.parse.fd;
	init_cub_el(&cub_el_flag);
	open_cub_file(filename, game);
	process_file_lines(game, &cub_el_flag);
	wrap_close(fd);
	process_map(game);
	validate_cub_file(game, &cub_el_flag);
}
