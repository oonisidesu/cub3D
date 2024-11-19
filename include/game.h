/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:34:31 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/19 17:02:28 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

// X11のキーコード
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

// 移動方向を示すオフセット
typedef struct s_offset
{
	int	dx;
	int	dy;
}		t_offset;

void	set_player_position(t_map *map, t_player *player);
void	move_player(t_map *map, t_player *player, t_offset offset);
int		handle_keypress(int keycode, t_game *game);

#endif
