/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:10:17 by lomajeru          #+#    #+#             */
/*   Updated: 2024/04/11 14:39:52 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_game(t_game *game, char *map_path)
{
	game->map = parse_map(map_path);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-1);
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long");
	if (!game->win)
		return (-1);
	game->img = mlx_new_image(game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE);
	if (!game->img)
		return (-1);
	load_images(game);
	draw_map(game, 0, 0);
	return (0);
}

static void	start_game(t_game *game)
{
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 1, 1L << 0, key_hook, game);
	mlx_hook(game->win, 17, 1L << 17, close_game, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = (t_game){0};
	if (argc != 2)
		error("Error\nInvalid number of arguments\n", 1);
	if (init_game(&game, argv[1]) == -1)
		error("Error\nmlx error\n", 2);
	start_game(&game);
	free_map(game.map.map, game.map.height);
	return (0);
}
