/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:03:23 by adchebbi          #+#    #+#             */
/*   Updated: 2026/04/15 12:03:25 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_grid(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!copy)
		error_exit("Malloc failed", game);
	i = 0;
	while (i < game->map.rows)
	{
		copy[i] = ft_strdup(game->map.grid[i]);
		if (!copy[i])
		{
			free_map(copy, i);
			error_exit("Malloc failed", game);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood(char **grid, int y, int x, t_game *game)
{
	if (y < 0 || y >= game->map.rows || x < 0 || x >= game->map.cols)
		return ;
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return ;
	grid[y][x] = 'V';
	flood(grid, y - 1, x, game);
	flood(grid, y + 1, x, game);
	flood(grid, y, x - 1, game);
	flood(grid, y, x + 1, game);
}

static void	verify_reachable(char **grid, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (grid[y][x] == 'C' || grid[y][x] == 'E')
			{
				free_map(grid, game->map.rows);
				error_exit("No valid path in map", game);
			}
			x++;
		}
		y++;
	}
	free_map(grid, game->map.rows);
}

void	check_path(t_game *game)
{
	char	**copy;

	copy = copy_grid(game);
	flood(copy, game->map.player_y, game->map.player_x, game);
	verify_reachable(copy, game);
}
