/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:34:21 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/21 16:16:57 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"
#include <math.h>

void	process_key_move(int keycode, t_player *player, t_offset *offset)
{
	if (keycode == KEY_W)
		move_handle(offset, player->dir_x, player->dir_y);
	else if (keycode == KEY_S)
		move_handle(offset, -player->dir_x, -player->dir_y);
	else if (keycode == KEY_A)
		move_handle(offset, -player->plane_x, -player->plane_y);
	else if (keycode == KEY_D)
		move_handle(offset, player->plane_x, player->plane_y);
}

void	process_key_rotation(int keycode, t_player *player)
{
	if (keycode == KEY_LEFT)
		rotation_handle(player, -ROT_SPEED);
	else if (keycode == KEY_RIGHT)
		rotation_handle(player, ROT_SPEED);
}

int	exit_program(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	t_offset	offset;

	ft_memset(&offset, 0, sizeof(t_offset));
	if (keycode == KEY_ESC)
		exit_program(game);
	else
	{
		process_key_move(keycode, &game->game_data.player, &offset);
		process_key_rotation(keycode, &game->game_data.player);
	}
	if (offset.dx != 0 || offset.dy != 0)
		move_player(&game->game_data.map, &game->game_data.player, offset);
	render_scene(game);
	return (0);
}
