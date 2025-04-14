/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:10:23 by lomajeru          #+#    #+#             */
/*   Updated: 2024/04/18 13:53:28 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img);
	exit(0);
	return (0);
}

static void	move_player(t_game *game, int x, int y)
{
	static int	moves;

	if (game->map.map[game->map.player_y + y][game->map.player_x + x] != '1')
	{
		if (game->map.map[game->map.player_y + y][game->map.player_x + x]
			== 'C')
		{
			game->map.collectibles--;
			game->map.map[game->map.player_y + y][game->map.player_x + x] = '0';
		}
		if (game->map.map[game->map.player_y + y][game->map.player_x + x] == 'E'
			&& game->map.collectibles == 0)
		{
			close_game(game);
		}
		else if (game->map.map[game->map.player_y + y][game->map.player_x + x]
			== 'E')
			return ;
		ft_putnbr_fd(moves++, 1);
		ft_putchar_fd('\n', 1);
		game->map.map[game->map.player_y][game->map.player_x] = '0';
		game->map.player_x += x;
		game->map.player_y += y;
		game->map.map[game->map.player_y][game->map.player_x] = 'P';
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_image(game->mlx, game->img);
		exit(0);
	}
	else if (keycode == W_KEY)
		move_player(game, 0, -1);
	else if (keycode == A_KEY)
		move_player(game, -1, 0);
	else if (keycode == S_KEY)
		move_player(game, 0, 1);
	else if (keycode == D_KEY)
		move_player(game, 1, 0);
	draw_map(game, 0, 0);
	return (0);
}
