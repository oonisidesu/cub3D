/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:34:31 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/18 19:33:59 by yooshima         ###   ########.fr       */
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
# define MOVE_SPEED 0.1

// 移動方向を示すオフセット
typedef struct s_offset
{
	double	dx;
	double	dy;
}			t_offset;

void		set_player_position(t_map *map, t_player *player);
void		move_player(t_map *map, t_player *player, t_offset offset);
void		move_handle(t_offset *offset, double dx, double dy);
void		rotation_handle(t_player *player, double rot_speed);
int			handle_keypress(int keycode, t_game *game);
void		render_scene(t_game *game);
int			exit_program(t_game *game);
int			handle_loop(t_game *game);

#endif
