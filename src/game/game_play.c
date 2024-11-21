/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:24:20 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/20 17:39:44 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

void	set_player_position(t_map *map, t_player *player)
{
	char	c;

	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
		{
			c = map->data[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				// プレイヤーの初期位置を設定
				player->x = j + 0.5; // 中央に設定
				player->y = i + 0.5;
				// プレイヤーの方向と視野平面を設定
				if (c == 'N')
				{
					player->dir_x = 0;
					player->dir_y = -1;
					player->plane_x = 0.66;
					player->plane_y = 0;
				}
				else if (c == 'S')
				{
					player->dir_x = 0;
					player->dir_y = 1;
					player->plane_x = -0.66;
					player->plane_y = 0;
				}
				else if (c == 'E')
				{
					player->dir_x = 1;
					player->dir_y = 0;
					player->plane_x = 0;
					player->plane_y = 0.66;
				}
				else if (c == 'W')
				{
					player->dir_x = -1;
					player->dir_y = 0;
					player->plane_x = 0;
					player->plane_y = -0.66;
				}
				// 開始位置を空白に変更
				map->data[i][j] = '0';
				return ;
			}
		}
	}
	fprintf(stderr, "Error: Player start position not found in map.\n");
	exit(EXIT_FAILURE);
}
