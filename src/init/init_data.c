/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:47:36 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/23 21:11:12 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ray.h"
#include <math.h>

void	init_cub_el(t_cub_el *cub_el_flag)
{
	ft_bzero(cub_el_flag, sizeof(t_cub_el));
}

void	init_game_data(t_cub3d *game_data)
{
	int	i;

	ft_bzero(game_data, sizeof(t_cub3d));
	i = 0;
	while (i < 3)
	{
		game_data->colors.floor[i] = -1;
		game_data->colors.ceiling[i] = -1;
		i++;
	}
}

void	init_game(t_game *game)
{
	init_mlx(game);
	init_game_data(&game->game_data);
}
