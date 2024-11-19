/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:47:36 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/18 16:58:21 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_game_data(t_cub3d *game)
{
	game->textures.north = NULL;
	game->textures.south = NULL;
	game->textures.west = NULL;
	game->textures.east = NULL;
	game->colors.floor[0] = 0;
	game->colors.floor[1] = 0;
	game->colors.floor[2] = 0;
	game->colors.ceiling[0] = 0;
	game->colors.ceiling[1] = 0;
	game->colors.ceiling[2] = 0;
	game->map.data = NULL;
	game->map.width = 0;
	game->map.height = 0;
}

void	init_minilibx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error initializing MinilibX");
		exit(EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx, 800, 600, "cub3D");
	if (!game->win)
	{
		perror("Error creating window");
		exit(1);
	}
}
