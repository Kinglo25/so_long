/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:10:25 by lomajeru          #+#    #+#             */
/*   Updated: 2024/04/11 14:37:33 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message, int exit_code)
{
	ft_putstr_fd(message, 2);
	exit(exit_code);
}

void	free_map(char **map, size_t height)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}
