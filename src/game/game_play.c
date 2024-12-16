/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:24:20 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/16 18:39:00 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

static void	set_player_direction_n_s(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (direction == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}

static void	set_player_direction_e_w(t_player *player, char direction)
{
	if (direction == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (direction == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

static bool	find_player_start_position(t_map *map, t_player *player)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->data[i][j] == 'N' || map->data[i][j] == 'S'
				|| map->data[i][j] == 'E' || map->data[i][j] == 'W')
			{
				player->x = j + 0.5;
				player->y = i + 0.5;
				set_player_direction_n_s(player, map->data[i][j]);
				set_player_direction_e_w(player, map->data[i][j]);
				map->data[i][j] = '0';
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

void	set_player_position(t_game *game)
{
	t_map		*map;
	t_player	*player;

	map = &game->game_data.map;
	player = &game->game_data.player;
	if (!find_player_start_position(map, player))
		print_error_free_exit("start position not found.\n", game);
}
