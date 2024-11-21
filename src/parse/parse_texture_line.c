/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:50:25 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/21 16:38:45 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <string.h>

// テクスチャ情報を解析し、t_texture構造体に保存
void	parse_texture_line(const char *line, t_texture *textures)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		textures->north.img = ft_strdup(line + 3); // テクスチャパスを保存
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		textures->south.img = ft_strdup(line + 3); // テクスチャパスを保存
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		textures->west.img = ft_strdup(line + 3); // テクスチャパスを保存
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		textures->east.img = ft_strdup(line + 3); // テクスチャパスを保存
	}
	else
	{
		fprintf(stderr, "Error: Unknown texture identifier in line: %s\n",
			line);
		exit(EXIT_FAILURE);
	}
}
