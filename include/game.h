/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:34:31 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/28 15:54:16 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"
# include "libft.h"
# include "ray.h"
# include <stdio.h>
# include <stdlib.h>

// X11のキーコード
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define ROT_SPEED 0.05
# define MOVE_SPEED 0.05

// 移動方向を示すオフセット
typedef struct s_offset
{
	double	dx;
	double	dy;
}			t_offset;

void		set_player_position(t_map *map, t_player *player);
void		move_player(t_map *map, t_player *player, t_offset offset);
int			handle_keypress(int keycode, t_game *game);
void		draw_vertical_line(t_game *game, int x, int start, int end,
				int color);
void		render_scene(t_game *game);
void		draw_wall(t_game *game, t_ray *ray, int x, int draw_start,
				int draw_end);
void		draw_floor_and_ceiling(t_game *game);
int			exit_program(t_game *game);
int			handle_loop(t_game *game);

#endif
