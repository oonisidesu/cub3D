/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:26:54 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/28 17:20:21 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "game.h"
#include <math.h>

void	move_player(t_map *map, t_player *player, t_offset offset)
{
	int	new_x;
	int	new_y;

	new_x = (int)(player->x + offset.dx);
	new_y = (int)(player->y + offset.dy);
	if (map->data[new_y][new_x] != '1')
	{
		player->x += offset.dx;
		player->y += offset.dy;
	}
}

void	move_handle(t_offset *offset, double dx, double dy)
{
	offset->dx = dx * MOVE_SPEED;
	offset->dy = dy * MOVE_SPEED;
}

void	rotation_handle(t_player *player, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed) - player->dir_y
		* sin(rot_speed);
	player->dir_y = old_dir_x * sin(rot_speed) + player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed) - player->plane_y
		* sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed) + player->plane_y
		* cos(rot_speed);
}
