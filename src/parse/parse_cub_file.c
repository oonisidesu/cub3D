/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:48:34 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/21 18:16:41 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "parse.h"
#include <fcntl.h>

// ファイルを解析してt_cub3d構造体にデータを保存
void	parse_cub_file(const char *filename, t_cub3d *game)
{
	int		fd;
	char	*line;
	char	*trimmed;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return ;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		// lineから改行を取り除く
		trimmed = ft_strtrim(line, "\n");
		free(line);
		line = trimmed;
		if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
			|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ",
				3) == 0)
		{
			parse_texture_line(line, &game->textures);
		}
		else if (ft_strncmp(line, "F ", 2) == 0)
		{
			parse_color_line(line + 2, game->colors.floor);
		}
		else if (ft_strncmp(line, "C ", 2) == 0)
		{
			parse_color_line(line + 2, game->colors.ceiling);
		}
		else if (ft_strlen(line) > 0)
		{
			// マップデータの行であると判断　TODO
			parse_map_line(line, &game->map);
		}
		free(line);
	}
	close(fd);
}
