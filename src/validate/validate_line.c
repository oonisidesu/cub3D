/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:27:28 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/23 23:57:43 by yooshima         ###   ########.fr       */
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

static bool	is_completed_elements(t_cub_el *cub_el_flag)
{
	return (cub_el_flag->has_no && cub_el_flag->has_so && cub_el_flag->has_we
		&& cub_el_flag->has_ea && cub_el_flag->has_f && cub_el_flag->has_c);
}

static bool	check_map_line(int fd, const char *line, t_game *game, \
							t_cub_el *cub_el_flag)
{
	bool	completed;
	char	*valid_char_ptr;
	char	*line_head_ptr;

	completed = is_completed_elements(cub_el_flag);
	line_head_ptr = (char *)line;
	while (*line)
	{
		valid_char_ptr = ft_strchr(VALID_MAP_CHARS, *line);
		if (!valid_char_ptr && !completed)
		{
			close(fd);
			free(line_head_ptr);
			print_error_free_exit("Invalid element in .cub file\n", game);
		}
		if (!valid_char_ptr)
		{
			close(fd);
			free(line_head_ptr);
			print_error_free_exit("Invalid character in map line\n", game);
		}
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

void	validate_line(int fd, const char *line, t_game *game, t_cub_el *cub_el_flag)
{
	if (is_empty_line(line))
		return ;
	if (is_texture_or_color_line(line))
		return ;
	if (check_map_line(fd, line, game, cub_el_flag))
		return ;
	free((char *)line);
	close(fd);
	print_error_free_exit("Invalid line in .cub file\n", game);
}
