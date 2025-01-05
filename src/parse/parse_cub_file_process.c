/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_file_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:48:34 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2025/01/05 15:40:41 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "utils.h"
#include "validate.h"
#include <fcntl.h>

static bool	is_texture_line(const char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (true);
	if (!ft_strncmp(line, "SO", 2))
		return (true);
	if (!ft_strncmp(line, "WE", 2))
		return (true);
	if (!ft_strncmp(line, "EA", 2))
		return (true);
	return (false);
}

static void	process_floor_color(const char *line, t_game *game,
		t_cub_el *cub_el_flag)
{
	if (cub_el_flag->has_f)
		print_error_free_exit("Duplicate floor color\n", game);
	cub_el_flag->has_f = true;
	if (!parse_color_line(remove_prefix_and_whitespace(line, "F",
				WHITESPACE_CHARS), game->game_data.colors.floor))
		print_error_free_exit("Failed to retrieve color.\n", game);
}

static void	process_ceiling_color(const char *line, t_game *game,
		t_cub_el *cub_el_flag)
{
	if (cub_el_flag->has_c)
		print_error_free_exit("Duplicate ceiling color\n", game);
	cub_el_flag->has_c = true;
	if (!parse_color_line(remove_prefix_and_whitespace(line, "C",
				WHITESPACE_CHARS), game->game_data.colors.ceiling))
		print_error_free_exit("Failed to retrieve color.\n", game);
}

static void	process_map_line_wrapper(const char *line, t_game *game,
		t_cub_el *cub_el_flag)
{
	if (cub_el_flag->has_no && cub_el_flag->has_so && cub_el_flag->has_we
		&& cub_el_flag->has_ea && cub_el_flag->has_f && cub_el_flag->has_c)
	{
		if (!parse_map_line(line, &game->game_data.map))
			print_error_free_exit("Failed to parse map line\n", game);
	}
	else
	{
		print_error_free_exit("Missing element in .cub file\n", game);
	}
}

void	process_cub_line(const char *line, t_game *game, t_cub_el *cub_el_flag)
{
	if (is_texture_line(line))
		process_texture(line, game, cub_el_flag);
	else if (!ft_strncmp(line, "F ", 2))
		process_floor_color(line, game, cub_el_flag);
	else if (!ft_strncmp(line, "C ", 2))
		process_ceiling_color(line, game, cub_el_flag);
	else if (ft_strlen(line) > 0)
		process_map_line_wrapper(line, game, cub_el_flag);
}
