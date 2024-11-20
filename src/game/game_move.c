/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:26:54 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/20 17:21:38 by ootsuboyosh      ###   ########.fr       */
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

// キー入力イベントを処理
int	handle_keypress(int keycode, t_game *game)
{
	t_offset	offset;

	// 構造体全体をゼロ初期化
	printf("[DEBUG] Key pressed: %d\n", keycode);
	ft_memset(&offset, 0, sizeof(t_offset));
	if (keycode == KEY_W)
		offset = (t_offset){0, -1}; // 上方向
	else if (keycode == KEY_S)
		offset = (t_offset){0, 1}; // 下方向
	else if (keycode == KEY_A)
		offset = (t_offset){-1, 0}; // 左方向
	else if (keycode == KEY_D)
		offset = (t_offset){1, 0}; // 右方向
	else if (keycode == KEY_ESC)
	{
		printf("Exiting game.\n");
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	// 移動処理を呼び出し
	move_player(&game->game_data.map, &game->game_data.player, offset);
	// 新しいシーンを描画
	render_scene(game);
	return (0);
}
