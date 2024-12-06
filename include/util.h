/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:50:31 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/06 17:31:36 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "cub3d.h"

void	put_pixel_to_image(t_game *game, int x, int y, int color);
void	load_texture(t_game *game, t_img *texture, char *path);
char	**resize_array(char **old_array, int old_size, int new_size);
void	display_usage_and_exit(const char *program_name);
void	print_error(const char *message);
void	print_error_exit(const char *message);
void	print_error_free(const char *message, t_game *game);
void	print_error_free_exit(const char *message, t_game *game);
void	free_game(t_game *game);
bool	is_prefix_and_whitespace(const char *line, const char *prefix,
			const char *whitespace_chars);

#endif