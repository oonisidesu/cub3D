/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:30:03 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/16 18:32:50 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>

// テクスチャ情報を保持する構造体
typedef struct s_texture
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
}				t_texture;

// 床と天井の色を保持する構造体
typedef struct s_color
{
	int			floor[3];
	int			ceiling[3];
}				t_color;

// マップデータを保持する構造体
typedef struct s_map
{
	char		**data;
	int			width;
	int			height;
}				t_map;

// プレイヤー情報を保持する構造体
typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

// 全体のゲームデータを保持するメイン構造体
typedef struct s_cub3d
{
	t_texture	textures;
	t_color		colors;
	t_map		map;
	t_player	player;
}				t_cub3d;

// MinilibX 関連情報を含むゲーム全体の構造体
typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_cub3d		game_data;
}				t_game;

#endif