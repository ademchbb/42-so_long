/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:03:56 by adchebbi          #+#    #+#             */
/*   Updated: 2026/04/15 12:03:57 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

static void	render_tile(t_game *game, int x, int y)
{
	char	c;

	c = game->map.grid[y][x];
	if (c == '1')
		put_tile(game, game->img.wall, x, y);
	else
	{
		put_tile(game, game->img.floor, x, y);
		if (c == 'C')
			put_tile(game, game->img.collect, x, y);
		else if (c == 'E')
			put_tile(game, game->img.exit_img, x, y);
		else if (c == 'P')
			put_tile(game, game->img.player, x, y);
	}
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
