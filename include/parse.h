/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:34:31 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/22 14:54:12 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"
# include "libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define MAP_INITIAL_SIZE 10
# define TEXTURE_IDENTIFIER_LENGTH 3
# define RESIZE_FACTOR 2
# define WHITESPACE_CHARS " \t\n\r\v\f"

bool	parse_color_line(const char *line, int color[3]);
void	parse_cub_file(const char *filename, t_game *game);
bool	parse_texture_line(const char *line, t_texture *textures,
			t_cub_el *cub_el_flag);
bool	parse_map_line(const char *line, t_map *map);
void	process_cub_line(const char *line, t_game *game, t_cub_el *cub_el_flag);
bool	process_texture(const char *line, t_game *game, t_cub_el *cub_el_flag);

#endif
