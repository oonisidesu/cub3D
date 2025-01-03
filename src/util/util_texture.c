/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:12:19 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/24 20:02:39 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	load_texture(t_game *game, t_img *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
		print_error_free_exit("Failed to load texture\n", game);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
}
