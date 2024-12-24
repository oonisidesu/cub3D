/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:30:03 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/24 18:06:19 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WINDOW_TITLE "cub3D"
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define KEYPRESS 2
# define KEYPRESS_MASK 1
# define DESTROY 17
# define DESTROY_MASK 0
# define ERROR 1
# define SUCCESS 0

typedef struct s_cub_el
{
	bool		has_no;
	bool		has_so;
	bool		has_we;
	bool		has_ea;
	bool		has_f;
	bool		has_c;
}				t_cub_el;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_texture
{
	char		*c_north;
	char		*c_south;
	char		*c_west;
	char		*c_east;
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		east;
	t_img		floor;
	t_img		ceiling;
}				t_texture;

typedef struct s_color
{
	int			floor[3];
	int			ceiling[3];
	bool		floor_set;
	bool		ceiling_set;
}				t_color;

typedef struct s_parse
{
	char		*line;
	int			fd;
}				t_parse;

typedef struct s_map
{
	char		**data;
	size_t		width;
	size_t		height;
	t_parse		parse;
}				t_map;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_cub3d
{
	t_texture	textures;
	t_color		colors;
	t_map		map;
	t_player	player;
}				t_cub3d;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_cub3d		game_data;
}				t_game;

#endif