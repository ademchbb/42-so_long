/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:03:42 by adchebbi          #+#    #+#             */
/*   Updated: 2026/04/15 12:03:44 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_direction(int keycode, int *dx, int *dy)
{
	*dx = 0;
	*dy = 0;
	if (keycode == KEY_W || keycode == KEY_UP)
		*dy = -1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		*dy = 1;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		*dx = -1;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		*dx = 1;
	else
		return (0);
	return (1);
}

static int	check_destination(t_game *game, char destination)
{
	if (destination == '1')
		return (0);
	if (destination == 'C')
		game->collected++;
	if (destination == 'E' && game->collected == game->map.collectibles)
	{
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		close_game(game);
	}
	if (destination == 'E')
		return (0);
	return (1);
}

static void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map.player_x + dx;
	new_y = game->map.player_y + dy;
	if (!check_destination(game, game->map.grid[new_y][new_x]))
		return ;
	game->map.grid[game->map.player_y][game->map.player_x] = '0';
	game->map.grid[new_y][new_x] = 'P';
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

int	handle_keypress(int keycode, t_game *game)
{
	int	dx;
	int	dy;

	if (keycode == KEY_ESC)
		close_game(game);
	if (get_direction(keycode, &dx, &dy))
	{
		move_player(game, dx, dy);
		render_map(game);
	}
	return (0);
}
