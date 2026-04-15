/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:03:17 by adchebbi          #+#    #+#             */
/*   Updated: 2026/04/15 12:03:19 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **grid, int rows)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (i < rows)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

static void	free_images(t_game *game)
{
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.floor)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.collect)
		mlx_destroy_image(game->mlx, game->img.collect);
	if (game->img.exit_img)
		mlx_destroy_image(game->mlx, game->img.exit_img);
}

int	close_game(t_game *game)
{
	free_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map.grid, game->map.rows);
	exit(0);
	return (0);
}

void	error_exit(char *msg, t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	if (game)
	{
		if (game->mlx)
		{
			free_images(game);
			if (game->win)
				mlx_destroy_window(game->mlx, game->win);
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free_map(game->map.grid, game->map.rows);
	}
	exit(1);
}
