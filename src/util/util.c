/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:23:51 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/07 16:22:28 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/utils.h"
#include "libft.h"

bool	is_prefix_and_whitespace(const char *line, const char *prefix,
		const char *whitespace_chars)
{
	size_t	prefix_len;

	if (line == NULL || prefix == NULL || whitespace_chars == NULL)
		return (false);
	prefix_len = ft_strlen(prefix);
	if (ft_strncmp(line, prefix, prefix_len) != 0)
		return (false);
	if (ft_strchr(whitespace_chars, line[prefix_len]) == NULL)
		return (false);
	return (true);
}

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
