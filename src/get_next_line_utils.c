/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:30:52 by lmajerus          #+#    #+#             */
/*   Updated: 2024/04/09 14:16:17 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strdup_gnl(char *s)
{
	size_t	i;
	char	*new;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	new = malloc(i + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new[i] = s[i];
		i++;
	}
	if (s[i])
		new[i++] = '\n';
	new[i] = '\0';
	erase_a_line(s);
	return (new);
}
