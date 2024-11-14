/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:56:49 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/14 17:57:27 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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

// 全体のゲームデータを保持するメイン構造体
typedef struct s_cub3d
{
	t_texture	textures;
	t_color		colors;
	t_map		map;
}				t_cub3d;

#endif
