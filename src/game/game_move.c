/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:26:54 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2025/01/06 15:30:18 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "game.h"
#include <math.h>

static void	move_player_x(t_map *map, t_player *player, double next_x,
		double margin)
{
	double	check_x;

	if (next_x > player->x)
		check_x = next_x + margin;
	else
		check_x = next_x - margin;
	if (check_x >= 0 && check_x < map->width
		&& map->data[(int)(player->y)][(int)check_x] != '1')
	{
		player->x = next_x;
	}
}

static void	move_player_y(t_map *map, t_player *player, double next_y,
		double margin)
{
	double	check_y;

	if (next_y > player->y)
		check_y = next_y + margin;
	else
		check_y = next_y - margin;
	if (check_y >= 0 && check_y < map->height
		&& map->data[(int)check_y][(int)(player->x)] != '1')
	{
		player->y = next_y;
	}
}

void	move_player(t_map *map, t_player *player, t_offset offset)
{
	double	margin;
	double	next_x;
	double	next_y;

	margin = 0.2;
	next_x = player->x + offset.dx;
	next_y = player->y + offset.dy;
	move_player_x(map, player, next_x, margin);
	move_player_y(map, player, next_y, margin);
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
