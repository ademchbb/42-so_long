/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:04:14 by adchebbi          #+#    #+#             */
/*   Updated: 2026/04/15 12:04:15 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "stdlib.h"
# include "stdio.h"
# include "unistd.h"
# include "fcntl.h"

# define TILE_SIZE 64

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
	int		collectibles;
	int		exit;
	int		player;
	int		player_x;
	int		player_y;
}	t_map;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collect;
	void	*exit_img;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	int		moves;
	int		collected;
}	t_game;

/* parsing */
void	parse_map(char *file, t_game *game);

/* map check */
void	check_map(t_game *game);

/* flood fill */
void	check_path(t_game *game);

/* game init */
void	init_game(t_game *game);

/* render */
void	render_map(t_game *game);

/* movement */
int		handle_keypress(int keycode, t_game *game);

/* cleanup */
void	free_map(char **grid, int rows);
void	error_exit(char *msg, t_game *game);
int		close_game(t_game *game);

#endif