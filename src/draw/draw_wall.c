/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:14:17 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2025/01/05 15:48:50 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "game.h"
#include "utils.h"
#include <math.h>

t_img	*select_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x < 0)
			return (&game->game_data.textures.west);
		else
			return (&game->game_data.textures.east);
	}
	else
	{
		if (ray->step_y < 0)
			return (&game->game_data.textures.north);
		else
			return (&game->game_data.textures.south);
	}
}

int	cal_tex_x(t_player *player, t_ray *ray, t_img *texture)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = player->y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = player->x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * texture->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
		tex_x = texture->width - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= texture->width)
		tex_x = texture->width - 1;
	return (tex_x);
}

void	draw_wall_texture(t_game *game, t_wall_params *params,
		t_draw_params *draw_params)
{
	int		y;
	int		tex_y;
	int		color;
	void	*pixel_address;

	y = params->draw_start;
	while (y < params->draw_end)
	{
		tex_y = (int)draw_params->tex_pos;
		if (tex_y < 0 || tex_y >= draw_params->texture->height)
			tex_y = 0;
		draw_params->tex_pos += draw_params->step;
		pixel_address = draw_params->texture->addr + (tex_y
				* draw_params->texture->line_length + draw_params->tex_x
				* (draw_params->texture->bits_per_pixel / 8));
		color = *(int *)pixel_address;
		put_pixel_to_image(game, params->x, y, color);
		y++;
	}
}

void	draw_wall(t_game *game, t_ray *ray, t_wall_params *params)
{
	t_draw_params	draw_params;

	draw_params.texture = select_texture(game, ray);
	if (!draw_params.texture)
		print_error_free_exit("Error: Texture not found\n", game);
	draw_params.tex_x = cal_tex_x(&game->game_data.player, ray,
			draw_params.texture);
	draw_params.step = (double)draw_params.texture->height
		/ params->line_height;
	draw_params.tex_pos = (params->draw_start - WINDOW_HEIGHT / 2
			+ params->line_height / 2) * draw_params.step;
	draw_wall_texture(game, params, &draw_params);
}
