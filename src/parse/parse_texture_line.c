/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:50:25 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/22 14:33:35 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "utils.h"
#include <string.h>

static bool	allocate_texture(char **texture_field, const char *path)
{
	*texture_field = ft_strdup(path);
	return (*texture_field != NULL);
}

static bool	set_texture(t_game *game, const char *line,
		bool *flag, char **texture_path)
{
	if (*flag)
		print_error_free_exit("Duplicate texture\n", game);
	*flag = true;
	line += TEXTURE_IDENTIFIER_LENGTH;
	return (allocate_texture(texture_path, line));
}

bool	is_texture_line(const char *line)
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

bool	process_texture(const char *line, t_game *game,
		t_cub_el *cub_el_flag)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (set_texture(game, line, &cub_el_flag->has_no,
				&game->game_data.textures.c_north));
	else if (!ft_strncmp(line, "SO ", 3))
		return (set_texture(game, line, &cub_el_flag->has_so,
				&game->game_data.textures.c_south));
	else if (!ft_strncmp(line, "WE ", 3))
		return (set_texture(game, line, &cub_el_flag->has_we,
				&game->game_data.textures.c_west));
	else if (!ft_strncmp(line, "EA ", 3))
		return (set_texture(game, line, &cub_el_flag->has_ea,
				&game->game_data.textures.c_east));
	return (false);
}
