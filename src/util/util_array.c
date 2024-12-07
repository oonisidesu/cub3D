/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:52:15 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/07 16:22:28 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/utils.h"

// 配列を拡張する関数
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
