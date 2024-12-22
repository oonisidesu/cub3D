/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/22 14:33:03 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "validate.h"
#include <stdbool.h>
#include <stdio.h>

static bool	is_empty_line(const char *line)
{
	return (ft_strlen(line) == 0);
}

static bool	completed_texture_and_color(t_cub_el *cub_el_flag)
{
	return (cub_el_flag->has_no && cub_el_flag->has_so && cub_el_flag->has_we
		&& cub_el_flag->has_ea && cub_el_flag->has_f && cub_el_flag->has_c);
}

static bool	is_map_line(const char *line, t_game *game, t_cub_el *cub_el_flag)
{
	bool	completed;
	char	*map_line;

	completed = completed_texture_and_color(cub_el_flag);
	while (*line)
	{
		map_line = ft_strchr(VALID_MAP_CHARS, *line);
		if (!map_line && !completed)
			print_error_free_exit("Invalid element in .cub file\n", game);
		if (!map_line)
			print_error_free_exit("Invalid character in map line\n", game);
		line++;
	}
	return (true);
}

static bool	is_texture_or_color_line(const char *line)
{
	return (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0
		|| ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0);
}

bool	validate_line(const char *line, t_game *game, t_cub_el *cub_el_flag)
{
	if (is_empty_line(line))
		return (true);
	if (is_texture_or_color_line(line))
		return (true);
	if (is_map_line(line, game, cub_el_flag))
		return (true);
	return (false);
}
