/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:23:51 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/24 19:35:35 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "utils.h"
#include <fcntl.h>

const char	*remove_prefix_and_whitespace(const char *line, const char *prefix,
		const char *whitespace_chars)
{
	size_t	prefix_len;

	if (line == NULL || prefix == NULL || whitespace_chars == NULL)
		return (NULL);
	prefix_len = ft_strlen(prefix);
	if (ft_strncmp(line, prefix, prefix_len) != 0)
		return (NULL);
	line += prefix_len;
	while (*line != '\0' && ft_strchr(whitespace_chars, *line) != NULL)
		line++;
	return (line);
}

bool	is_whitespace_only(const char *line)
{
	while (*line)
	{
		if (!ft_strchr(WHITESPACE_CHARS, *line))
			return (false);
		line++;
	}
	return (true);
}

void	open_cub_file(const char *filename, t_game *game)
{
	int	*fd;

	fd = &game->game_data.map.parse.fd;
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		print_error_free_exit("Failed to open file\n", game);
}

char	*read_and_trim_line(int fd)
{
	char	*line;
	char	*new_line_ptr;

	line = get_line(fd);
	if (line == NULL)
		return (NULL);
	new_line_ptr = ft_strchr(line, '\n');
	if (new_line_ptr)
		*new_line_ptr = '\0';
	return (line);
}

void	wrap_close(int *fd)
{
	if (*fd != FD_CLOSED && close(*fd) == -1)
		print_error_exit("Failed to close file\n");
	*fd = FD_CLOSED;
}
