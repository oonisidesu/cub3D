/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:26:54 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/21 18:36:27 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "game.h"

// プレイヤーの移動処理
void	move_player(t_map *map, t_player *player, t_offset offset)
{
	int	new_x;
	int	new_y;

	new_x = (int)(player->x + offset.dx);
	new_y = (int)(player->y + offset.dy);
	// 壁を通り抜けないようにする
	if (map->data[new_y][new_x] != '1')
	{
		player->x += offset.dx;
		player->y += offset.dy;
		printf("[DEBUG] Player moved to: x = %.1f, y = %.1f\n", player->x,
			player->y);
	}
	else
	{
		printf("[DEBUG] Cannot move to: x = %d, y = %d (wall)\n", new_x, new_y);
	}
}
