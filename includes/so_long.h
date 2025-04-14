/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:15:04 by lomajeru          #+#    #+#             */
/*   Updated: 2024/04/11 14:29:38 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "../includes/get_next_line.h"

# define TILE_SIZE 32
# define ESC_KEY 53
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2

typedef struct s_map
{
	size_t		width;
	size_t		height;
	size_t		collectibles;
	size_t		exit;
	size_t		player;
	size_t		player_x;
	size_t		player_y;
	char		**map;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;

	t_map	map;

	void	*player;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*floor;
}	t_game;

void	error(char *message, int exit_code);
void	check_map(t_map *map);
t_map	parse_map(char *map_path);
void	load_images(t_game *game);
void	draw_map(t_game *game, size_t x, size_t y);
int		close_game(t_game *game);
int		key_hook(int keycode, t_game *game);
void	free_map(char **map, size_t height);

#endif
