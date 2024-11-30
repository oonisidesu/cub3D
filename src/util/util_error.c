/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:55:25 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/11/30 16:21:44 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/util.h"

void	display_usage_and_exit(const char *program_name)
{
	fprintf(stderr, "Usage: %s <map.cub>\n", program_name);
	exit(EXIT_FAILURE);
}

void	print_error(const char *message)
{
	printf("Error\n");
	perror(message);
}

void	print_error_exit(const char *message)
{
	print_error(message);
	exit(EXIT_FAILURE);
}

void	print_error_free(const char *message, t_game *game)
{
	printf("Error\n");
	perror(message);
	free_game(game);
}

void	print_error_free_exit(const char *message, t_game *game)
{
	print_error_free(message, game);
	exit(EXIT_FAILURE);
}
