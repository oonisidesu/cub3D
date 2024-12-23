/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:36:45 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/23 20:26:21 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

void	free_textures(t_texture *textures)
{
	if (textures->c_north)
		free(textures->c_north);
	if (textures->c_south)
		free(textures->c_south);
	if (textures->c_west)
		free(textures->c_west);
	if (textures->c_east)
		free(textures->c_east);
}

void	free_map(t_map *map)
{
	size_t	i;

	if (map->data)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->data[i])
				free(map->data[i]);
			i++;
		}
		free(map->data);
	}
}

void	free_mlx_resources(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->game_data.textures.north.img)
		mlx_destroy_image(game->mlx, game->game_data.textures.north.img);
	if (game->game_data.textures.south.img)
		mlx_destroy_image(game->mlx, game->game_data.textures.south.img);
	if (game->game_data.textures.west.img)
		mlx_destroy_image(game->mlx, game->game_data.textures.west.img);
	if (game->game_data.textures.east.img)
		mlx_destroy_image(game->mlx, game->game_data.textures.east.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	free_game(t_game *game)
{
	free_textures(&game->game_data.textures);
	free_map(&game->game_data.map);
	free_mlx_resources(game);
}

void	free_array(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
