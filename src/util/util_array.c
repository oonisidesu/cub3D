/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:52:15 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/09 21:41:27 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

char	**resize_array(char **old_array, int old_size, int new_size)
{
	char	**new_array;
	int		i;

	new_array = malloc(sizeof(char *) * new_size);
	if (!new_array)
	{
		perror("Error allocating memory for new array");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < old_size)
	{
		new_array[i] = old_array[i];
		i++;
	}
	free(old_array);
	return (new_array);
}

size_t	get_map_max_height(char **map)
{
	size_t	height;

	height = 0;
	while (map[height] != NULL)
		height++;
	return (height);
}

size_t	get_map_max_width(char **map)
{
	size_t	width;
	size_t	max_width;
	size_t	i;

	i = 0;
	max_width = 0;
	while (map[i] != NULL)
	{
		width = ft_strlen(map[i]);
		if (width > max_width)
			max_width = width;
		i++;
	}
	return (max_width);
}

char	**allocate_map_memory(size_t height, size_t width)
{
	char	**map;
	size_t	i;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = malloc(sizeof(char) * (width + 1));
		if (!map[i])
		{
			while (i > 0)
				free(map[--i]);
			free(map);
			return (NULL);
		}
		ft_memset(map[i], '0', width);
		map[i][width] = '\0';
		i++;
	}
	map[height] = NULL;
	return (map);
}
