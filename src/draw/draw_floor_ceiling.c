/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:14:17 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/28 16:11:25 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "util.h"
#include <math.h>

void	draw_ceiling(t_game *game, int ceiling_color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			put_pixel_to_image(game, x, y, ceiling_color);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_game *game, int floor_color)
{
	int	x;
	int	y;

	y = WINDOW_HEIGHT / 2;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			put_pixel_to_image(game, x, y, floor_color);
			x++;
		}
		y++;
	}
}

void	draw_floor_and_ceiling(t_game *game)
{
	int	floor_color;
	int	ceiling_color;

	floor_color = (game->game_data.colors.floor[0] << 16) | \
				(game->game_data.colors.floor[1] << 8) | \
				(game->game_data.colors.floor[2]);
	ceiling_color = (game->game_data.colors.ceiling[0] << 16) | \
					(game->game_data.colors.ceiling[1] << 8) | \
					(game->game_data.colors.ceiling[2]);
	draw_ceiling(game, ceiling_color);
	draw_floor(game, floor_color);
}
