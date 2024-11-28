/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:33:27 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/28 17:05:46 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "game.h"
#include "init.h"
#include "ray.h"
#include "util.h"

void	process_column(t_game *game, t_ray *ray, t_wall_params *wall_params)
{
	init_ray(game, ray, wall_params->x);
	perform_dda(game, ray);
	calculate_wall_distance(ray, &game->game_data.player);
	init_wall_params(wall_params, ray);
	draw_wall(game, ray, wall_params);
}

void	render_scene(t_game *game)
{
	t_ray			ray;
	t_wall_params	wall_params;

	draw_floor_and_ceiling(game);
	wall_params.x = 0;
	while (wall_params.x < WINDOW_WIDTH)
	{
		process_column(game, &ray, &wall_params);
		wall_params.x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

int	handle_loop(t_game *game)
{
	render_scene(game);
	return (0);
}
