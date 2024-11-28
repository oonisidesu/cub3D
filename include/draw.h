/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:12:04 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/28 16:18:27 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "cub3d.h"
# include "libft.h"
# include "ray.h"

typedef struct s_wall_params
{
	int	draw_start;
	int	draw_end;
	int	line_height;
	int	x;
}		t_wall_params;

void	draw_wall(t_game *game, t_ray *ray, t_wall_params *params);
void	draw_floor_and_ceiling(t_game *game);

#endif