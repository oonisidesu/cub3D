/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:56:47 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/15 15:50:18 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

// テクスチャ情報を表示する関数
void	display_textures(t_texture *textures)
{
	printf("North Texture: %s\n", textures->north);
	printf("South Texture: %s\n", textures->south);
	printf("West Texture: %s\n", textures->west);
	printf("East Texture: %s\n", textures->east);
}

// カラー情報を表示する関数
void	display_colors(t_color *colors)
{
	printf("Floor Color: RGB(%d, %d, %d)\n", colors->floor[0], colors->floor[1],
		colors->floor[2]);
	printf("Ceiling Color: RGB(%d, %d, %d)\n", colors->ceiling[0],
		colors->ceiling[1], colors->ceiling[2]);
}

// マップデータを表示する関数
void	display_map(t_map *map)
{
	printf("Map Width: %d, Height: %d\n", map->width, map->height);
	for (int i = 0; i < map->height; i++)
	{
		printf("%s\n", map->data[i]);
	}
}

// 全体のゲームデータを表示する関数
void	display_cub3d(t_cub3d *cub3d)
{
	printf("=== Displaying Cub3D Data ===\n");
	display_textures(&cub3d->textures);
	display_colors(&cub3d->colors);
	display_map(&cub3d->map);
	printf("=============================\n");
}
