/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:03:36 by adchebbi          #+#    #+#             */
/*   Updated: 2026/04/15 12:03:39 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if ((int)ft_strlen(game->map.grid[i]) != game->map.cols)
			error_exit("Map is not rectangular", game);
		i++;
	}
}

static void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.cols)
	{
		if (game->map.grid[0][i] != '1'
		|| game->map.grid[game->map.rows - 1][i] != '1')
			error_exit("Map is not enclosed by walls", game);
		i++;
	}
	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.grid[i][0] != '1'
			|| game->map.grid[i][game->map.cols - 1] != '1')
			error_exit("Map is not enclosed by walls", game);
		i++;
	}
}

static void	count_elements(t_game *game, int y, int x)
{
	char	c;

	c = game->map.grid[y][x];
	if (c == 'C')
		game->map.collectibles++;
	else if (c == 'E')
		game->map.exit++;
	else if (c == 'P')
	{
		game->map.player++;
		game->map.player_x = x;
		game->map.player_y = y;
	}
	else if (c != '0' && c != '1')
		error_exit("Invalid character in map", game);
}

static void	check_elements(t_game *game)
{
	int	y;
	int	x;

	game->map.collectibles = 0;
	game->map.exit = 0;
	game->map.player = 0;
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			count_elements(game, y, x);
			x++;
		}
		y++;
	}
	if (game->map.collectibles < 1)
		error_exit("Map must have at least one collectible", game);
	if (game->map.exit != 1)
		error_exit("Map must have exactly one exit", game);
	if (game->map.player != 1)
		error_exit("Map must have exactly one player", game);
}

void	check_map(t_game *game)
{
	check_rectangular(game);
	check_walls(game);
	check_elements(game);
}
