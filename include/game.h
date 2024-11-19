/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:34:31 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/16 18:41:41 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

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
