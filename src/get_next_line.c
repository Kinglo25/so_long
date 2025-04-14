/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:42:59 by lmajerus          #+#    #+#             */
/*   Updated: 2024/04/09 14:16:09 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	s3 = malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
			s3[j++] = s1[i++];
		free(s1);
	}
	i = 0;
	if (s2)
		while (s2[i])
			s3[j++] = s2[i++];
	s3[j] = '\0';
	return (s3);
}

void	erase_a_line(char *s)
{
	char	*end_of_line;
	size_t	i;

	i = 0;
	end_of_line = ft_strchr(s, '\n');
	if (!end_of_line)
		return ;
	while (end_of_line[(i + 1)])
	{
		s[i] = end_of_line[(i + 1)];
		i++;
	}
	s[i] = '\0';
	return ;
}

static int	error_free(char *line, char **s, int x)
{
	if (s)
	{
		if (x == 0)
		{
			free(line);
			free(*s);
			*s = NULL;
			return (0);
		}
		if (x == -1)
		{
			free(line);
			free(*s);
			*s = NULL;
			return (-1);
		}
	}
	return (19);
}

char	*line_returner(char **save, char *line)
{
	if (ft_strchr(*save, '\n'))
	{
		line = ft_strdup_gnl(*save);
		if (!line)
			return (error_free(line, save, -1), NULL);
		return (line);
	}
	if (!ft_strlen(*save))
		return (error_free(NULL, save, 0), NULL);
	line = ft_strdup_gnl(*save);
	if (!line)
		return (error_free(line, save, -1), NULL);
	return (error_free(NULL, save, 0), line);
}

char	*get_next_line(int fd)
{
	int				rv;
	static char		*save;
	char			buff[BUFFER_SIZE + 1];
	char			*line;

	line = NULL;
	rv = 1;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(save, '\n') && rv > 0)
	{
		rv = read(fd, buff, BUFFER_SIZE);
		if (rv < 0)
			return (error_free(line, &save, -1), NULL);
		buff[rv] = '\0';
		save = ft_free_strjoin(save, buff);
		if (!save)
			return (error_free(line, &save, -1), NULL);
	}
	return (line_returner(&save, line));
}
