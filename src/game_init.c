/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:03:29 by adchebbi          #+#    #+#             */
/*   Updated: 2026/04/15 12:03:31 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_texture(t_game *game, void **texture, char *path)
{
	int	w;
	int	h;

	*texture = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!texture)
		error_exit("Failed to load texture", game);
}

static void	load_textures(t_game *game)
{
	load_texture(game, &game->img.wall, "textures/wall.xpm");
	load_texture(game, &game->img.floor, "textures/floor.xpm");
	load_texture(game, &game->img.player, "textures/player.xpm");
	load_texture(game, &game->img.collect, "textures/collect.xpm");
	load_texture(game, &game->img.exit_img, "textures/exit.xpm");
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("MLX initialisation failed", game);
	game->win = mlx_new_window(game->mlx,
			game->map.cols * TILE_SIZE,
			game->map.rows * TILE_SIZE,
			"so+long");
	if (!game->win)
		error_exit("Failed to create window", game);
	load_textures(game);
	game->moves = 0;
	game->collected = 0;
}
