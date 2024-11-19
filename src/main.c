/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:32:55 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/16 18:44:39 by ootsuboyosh      ###   ########.fr       */
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
	t_game	game;

	(void)argc;
	// MinilibX の初期化
	init_minilibx(&game);
	// ゲームデータの初期化とマップの読み込み
	init_game_data(&game.game_data);
	parse_cub_file(argv[1], &game.game_data);
	set_player_position(&game.game_data.map, &game.game_data.player);
	// イベントフックの設定
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	// イベントループ
	mlx_loop(game.mlx);
	return (0);
}
