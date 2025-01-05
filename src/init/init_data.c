/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:47:36 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/25 23:55:05 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parse.h"
#include "ray.h"
#include <math.h>

void	init_cub_el(t_cub_el *cub_el_flag)
{
	ft_bzero(cub_el_flag, sizeof(t_cub_el));
}

void	init_game(t_game *game)
{
	int	i;

	ft_bzero(game, sizeof(t_cub3d));
	i = 0;
	while (i < 3)
	{
		game->game_data.colors.floor[i] = -1;
		game->game_data.colors.ceiling[i] = -1;
		i++;
	}
	game->game_data.map.parse.fd = FD_CLOSED;
}
