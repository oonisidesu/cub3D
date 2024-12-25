/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:45:22 by yootsubo          #+#    #+#             */
/*   Updated: 2024/12/25 10:47:49 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

bool	append_char(char **str, char c)
{
	char	*new;
	char	join[2];

	join[0] = c;
	join[1] = '\0';
	new = ft_strjoin(*str, join);
	if (!new)
		return (false);
	wrap_free(*str);
	*str = new;
	return (true);
}

char	*get_line(int fd)
{
	char	buf;
	char	*result;
	int		read_size;

	buf = 0;
	result = ft_strdup("");
	while (true)
	{
		read_size = read(fd, &buf, 1);
		if (read_size == -1 || (read_size == 0 && !ft_strlen(result)))
			return (wrap_free (result), NULL);
		if (!append_char(&result, buf))
			return (NULL);
		if (buf == '\n' || read_size == 0)
			break ;
	}
	return (result);
}
