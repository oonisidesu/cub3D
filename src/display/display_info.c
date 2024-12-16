/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:56:47 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/16 18:34:38 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	display_textures(t_texture *textures)
{
	printf("North Texture: %p\n", (void *)textures->north.img);
	printf("South Texture: %p\n", (void *)textures->south.img);
	printf("West Texture: %p\n", (void *)textures->west.img);
	printf("East Texture: %p\n", (void *)textures->east.img);
	printf("Floor Texture: %p\n", (void *)textures->floor.img);
	printf("Ceiling Texture: %p\n", (void *)textures->ceiling.img);
}

void	display_colors(t_color *colors)
{
	printf("Floor Color: RGB(%d, %d, %d)\n", colors->floor[0], colors->floor[1],
		colors->floor[2]);
	printf("Ceiling Color: RGB(%d, %d, %d)\n", colors->ceiling[0],
		colors->ceiling[1], colors->ceiling[2]);
}

void	display_map(t_map *map)
{
	size_t	row;

	row = 0;
	printf("Map Width: %zu, Height: %zu\n", map->width, map->height);
	while (row < map->height)
	{
		printf("%s\n", map->data[row]);
		row++;
	}
}

void	display_cub3d(t_cub3d *cub3d)
{
	printf("=== Displaying Cub3D Data ===\n");
	display_textures(&cub3d->textures);
	display_colors(&cub3d->colors);
	display_map(&cub3d->map);
	printf("\n=============================\n");
}
