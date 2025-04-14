/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:10:27 by lomajeru          #+#    #+#             */
/*   Updated: 2024/04/18 13:47:38 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	i;
	int	j;

	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&i, &j);
	game->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&i, &j);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&i, &j);
}

void	draw_map(t_game *game, size_t i, size_t j)
{
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall,
					j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map.map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player,
					j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map.map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collectible,
					j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map.map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit,
					j * TILE_SIZE, i * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->floor,
					j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}
