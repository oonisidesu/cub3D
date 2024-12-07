/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:38:01 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/07 16:21:19 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "display.h"
#include "game.h"
#include "get_next_line.h"
#include "init.h"
#include "parse.h"
#include "utils.h"
#include "validate.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_game	game;

	if (validate_args(argc, argv) == ERROR)
		print_error_exit("Invalid arguments");
	init_game(&game);
	parse_cub_file(argv[1], &game);
	init_textures(&game);
	set_player_position(&game.game_data.map, &game.game_data.player);
	mlx_loop_hook(game.mlx, handle_loop, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, (int (*)())exit_program, &game);
	mlx_loop(game.mlx);
	return (0);
}
