/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:45:22 by yootsubo          #+#    #+#             */
/*   Updated: 2024/11/14 18:19:56 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

static char	*ft_strtrim_l(char const *s1, int set, int *e_flag)
{
	char	*new_str;
	size_t	start;
	size_t	end;

	end = ft_strlen(s1);
	start = ft_strchr_gnl(s1, set);
	if (start == 0)
		new_str = (char *)malloc((end + 1) * sizeof(char));
	else
		new_str = (char *)malloc((start + 1) * sizeof(char));
	if (new_str == NULL)
	{
		*e_flag = 1;
		return (NULL);
	}
	if (start == 0)
		ft_strlcpy(new_str, s1, end + 1);
	else
		ft_strlcpy(new_str, s1, start + 1);
	return (new_str);
}

static char	*ft_strtrim_r(char const *s1, int set, int *e_flag)
{
	char	*new_str;
	size_t	start;
	size_t	end;

	end = ft_strlen(s1);
	start = ft_strchr_gnl(s1, set);
	if (start > 0 && start != end)
		new_str = (char *)malloc((end - start + 1) * sizeof(char));
	else
	{
		*e_flag = 2;
		new_str = NULL;
	}
	if (new_str == NULL && *e_flag == 0)
	{
		*e_flag = 1;
		return (NULL);
	}
	if (start > 0 && start != end)
		ft_strlcpy(new_str, s1 + start, end - start + 1);
	return (new_str);
}

static char	*free_and_return(char **s1, char **s2, char **s3, int nl_flag)
{
	if (s1 != NULL)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 != NULL)
	{
		free(*s2);
		*s2 = NULL;
	}
	if (s3 != NULL)
	{
		free(*s3);
		*s3 = NULL;
	}
	if (nl_flag)
		return (NULL);
	return ("");
}

static char	*read_append(int fd, char *save, char *buf, int line_break_flag)
{
	char	*tmpsave;
	int		r;

	while (line_break_flag == 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (free_and_return(&buf, NULL, NULL, 1));
		if (r == 0)
			break ;
		buf[r] = '\0';
		if (save == NULL)
			save = ft_strdup("");
		tmpsave = save;
		save = ft_strjoin(tmpsave, buf);
		if (save == NULL)
			return (free_and_return(&buf, &save, &tmpsave, 1));
		free_and_return(&tmpsave, NULL, NULL, 0);
		line_break_flag = ft_strchr_gnl(save, '\n');
	}
	free_and_return(&buf, NULL, NULL, 0);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*buf;
	char		*tmpsave;
	char		*line;
	int			e_flag;

	if (OPEN_MAX < fd || fd < 0 || BUFFER_SIZE < 0 || INT_MAX < BUFFER_SIZE)
		return (NULL);
	buf = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	save[fd] = read_append(fd, save[fd], buf, 0);
	if (save[fd] == NULL)
		return (NULL);
	e_flag = 0;
	line = ft_strtrim_l(save[fd], '\n', &e_flag);
	if (e_flag == 1)
		return (free_and_return(&save[fd], NULL, NULL, 1));
	tmpsave = save[fd];
	save[fd] = ft_strtrim_r(tmpsave, '\n', &e_flag);
	if (e_flag == 1)
		return (free_and_return(&tmpsave, &line, NULL, 1));
	free_and_return(&tmpsave, NULL, NULL, 0);
	return (line);
}
