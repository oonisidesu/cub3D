/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:50:31 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2025/01/05 16:15:22 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

void		put_pixel_to_image(t_game *game, int x, int y, int color);
void		load_texture(t_game *game, t_img *texture, char *path);
char		**resize_array(char **old_array, size_t old_size, size_t new_size);
size_t		get_map_max_height(char **map);
size_t		get_map_max_width(t_map *map);
char		**allocate_map_memory(size_t height, size_t width);
void		print_error(const char *message);
void		print_error_exit(const char *message);
void		print_error_free(const char *message, t_game *game);
void		print_error_free_exit(const char *message, t_game *game);
void		free_game(t_game *game);
void		free_array(char **array);
const char	*remove_prefix_and_whitespace(const char *line, const char *prefix,
				const char *whitespace_chars);
void		open_cub_file(const char *filename, t_game *game);
char		*read_and_trim_line(int fd);
void		wrap_close(int *fd);
void		free_parse_obj(t_parse *parse);

#endif