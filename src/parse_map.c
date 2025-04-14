/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:10:21 by lomajeru          #+#    #+#             */
/*   Updated: 2024/04/18 13:50:50 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_map(char *map_path, t_map *map, size_t i)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error("Error\nInvalid map path\n", 3);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->height++;
		free(line);
	}
	free(line);
	close(fd);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error("Error\nInvalid map path\n", 4);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		error("Error\nMalloc failed\n", 5);
	while (i < map->height)
		map->map[i++] = get_next_line(fd);
	close(fd);
}

static void	check_extension(char *map_path, char *extension)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(map_path);
	j = ft_strlen(extension);
	if (i < j || ft_strncmp(map_path + i - j, extension, j))
		error("Error\nInvalid map extension\n", 6);
}

t_map	parse_map(char *map_path)
{
	t_map	map;

	map = (t_map){};
	check_extension(map_path, ".ber");
	fill_map(map_path, &map, 0);
	map.map[map.height] = NULL;
	map.width = ft_strlen(map.map[0]) - 1;
	check_map(&map);
	return (map);
}
