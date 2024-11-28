/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:19:18 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/25 18:56:27 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	display_map_with_player(t_map *map, t_player *player)
{
	int	row;
	int	col;

	row = 0;
	printf("\n=== Current Map with Player ===\n");
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if ((int)player->x == col && (int)player->y == row)
				printf("P ");
			else
				printf("%c ", map->data[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
	printf("===============================\n");
}
