/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:19:18 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/16 18:19:34 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	display_map_with_player(t_map *map, t_player *player)
{
	printf("\n=== Current Map with Player ===\n");
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
		{
			// プレイヤー位置を特別に表示
			if ((int)player->x == j && (int)player->y == i)
				printf("P ");
			else
				printf("%c ", map->data[i][j]);
		}
		printf("\n");
	}
	printf("===============================\n");
}
