/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:32:55 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/16 18:21:35 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "display.h"
#include "game.h"
#include "get_next_line.h"
#include "init.h"
#include "parse.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// エラーメッセージと使用方法の表示
void	display_usage_and_exit(const char *program_name)
{
	fprintf(stderr, "Usage: %s <map.cub>\n", program_name);
	exit(1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		display_usage_and_exit(argv[0]);
	}
	t_cub3d game;                   // ゲームデータの構造体を作成
	init_game_data(&game);          // ゲームデータの初期化
	parse_cub_file(argv[1], &game); // パース処理の呼び出し
	// プレイヤーの位置と方向を設定
	set_player_position(&game.map, &game.player);
	// マップとプレイヤーの表示
	display_map_with_player(&game.map, &game.player);
	// TODO: パースされたデータを用いて描画処理やゲームロジックを開始する
	// 正常終了
	return (0);
}
