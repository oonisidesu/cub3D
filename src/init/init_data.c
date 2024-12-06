/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:47:36 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/06 16:32:35 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ray.h"
#include <math.h>

void	init_cub_el(t_cub_el *cub_el_flag)
{
	cub_el_flag->has_no = false;
	cub_el_flag->has_so = false;
	cub_el_flag->has_we = false;
	cub_el_flag->has_ea = false;
	cub_el_flag->has_f = false;
	cub_el_flag->has_c = false;
}

void	init_game_data(t_cub3d *game_data)
{
	int	i;

	game_data->textures.c_north = NULL;
	game_data->textures.c_south = NULL;
	game_data->textures.c_west = NULL;
	game_data->textures.c_east = NULL;
	game_data->map.data = NULL;
	game_data->map.width = 0;
	game_data->map.height = 0;
	i = 0;
	while (i < 3)
	{
		game_data->colors.floor[i] = -1;
		game_data->colors.ceiling[i] = -1;
		i++;
	}
	game_data->player.x = 0;
	game_data->player.y = 0;
	game_data->player.dir_x = 0;
	game_data->player.dir_y = 0;
	game_data->player.plane_x = 0;
	game_data->player.plane_y = 0;
}

void	init_game(t_game *game)
{
	init_mlx(game);
	init_game_data(&game->game_data);
}
