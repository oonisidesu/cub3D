/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:38:01 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/17 20:07:43 by yooshima         ###   ########.fr       */
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

	if (validate_args(argc, argv))
		print_error_exit("Invalid arguments");
	init_game(&game);
	parse_cub_file(argv[1], &game);
	init_textures(&game);
	set_player_position(&game);
	mlx_loop_hook(game.mlx, handle_loop, &game);
	mlx_hook(game.win, KEYPRESS, KEYPRESS_MASK, handle_keypress, &game);
	mlx_hook(game.win, DESTROY, DESTROY_MASK, (int (*)())exit_program, &game);
	mlx_loop(game.mlx);
	return (0);
}
