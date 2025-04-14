/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:44:09 by lomajeru          #+#    #+#             */
/*   Updated: 2024/04/19 16:17:41 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_chars(t_map *map, size_t i, size_t j)
{
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
				&& map->map[i][j] != 'P' && map->map[i][j]
				!= 'E' && map->map[i][j] != 'C')
				error("Error\nInvalid map\n", 9);
			j++;
			if (map->map[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
				map->player++;
			}
			if (map->map[i][j] == 'E')
				map->exit++;
			if (map->map[i][j] == 'C')
				map->collectibles++;
		}
		i++;
	}
	if (map->player != 1 || map->exit != 1 || map->collectibles < 1)
		error("Error\nInvalid map\n", 10);
}

static void	check_map_borders(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->map[i]) - 1 != map->width)
			error("Error\nInvalid map\n", 6);
		i++;
	}
	i = 0;
	while (i < map->height - 1)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			error("Error\nInvalid map\n", 7);
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			error("Error\nInvalid map\n", 8);
		i++;
	}
}

static size_t	map_flood_fill(t_map *map, size_t x,
				size_t y, char **copied_map)
{
	static size_t	collected;
	static size_t	exit_count;

	if (exit_count >= 1 && collected == map->collectibles)
		return (1);
	if (x < 0 || y < 0 || x > map->width || y > map->height)
		return (0);
	if (copied_map[y][x] == 'C')
		collected++;
	if (copied_map[y][x] == 'E')
		exit_count++;
	if (copied_map[y][x] == '1' || copied_map[y][x] == 'V'
	|| (copied_map[y][x] == 'E' && collected != map->collectibles))
		return (0);
	copied_map[y][x] = 'V';
	if (map_flood_fill(map, x + 1, y, copied_map)
		|| map_flood_fill(map, x - 1, y, copied_map)
		|| map_flood_fill(map, x, y + 1, copied_map)
		|| map_flood_fill(map, x, y - 1, copied_map))
		return (1);
	return (0);
}

static char	**copy_map(t_map *map)
{
	size_t	i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * map->height);
	if (!copy)
		error("Error\nMalloc failed\n", 13);
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->map[i]);
		if (!copy[i])
			error("Error\nMalloc failed\n", 14);
		i++;
	}
	return (copy);
}

void	check_map(t_map *map)
{
	char	**copied_map;

	check_map_borders(map);
	check_map_chars(map, 0, 0);
	copied_map = copy_map(map);
	if (map->height < 3 || map->width < 3)
		error("Error\nInvalid map\n", 11);
	if (!map_flood_fill(map, map->player_x, map->player_y, copied_map))
		error("Error\nInvalid map\n", 12);
	free_map(copied_map, map->height);
}
