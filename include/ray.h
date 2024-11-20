/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:34:44 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/20 17:57:58 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "cub3d.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

// レイキャスティング用の一時データ構造体
typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}			t_ray;

void		initialize_ray(t_game *game, t_ray *ray, int x);
void		perform_dda(t_game *game, t_ray *ray);
void		calculate_wall_distance(t_ray *ray, t_player *player);

#endif