/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:55:25 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/12/26 00:00:45 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include <unistd.h>

void	print_error(const char *message)
{
	char	*error_prefix;

	error_prefix = "Error\n";
	write(STDERR_FILENO, error_prefix, ft_strlen(error_prefix));
	write(STDERR_FILENO, message, ft_strlen(message));
}

void	print_error_exit(const char *message)
{
	print_error(message);
	exit(EXIT_FAILURE);
}

void	print_error_free(const char *message, t_game *game)
{
	print_error(message);
	free_game(game);
}

void	print_error_free_exit(const char *message, t_game *game)
{
	print_error_free(message, game);
	exit(EXIT_FAILURE);
}
