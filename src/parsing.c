/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:03:51 by adchebbi          #+#    #+#             */
/*   Updated: 2026/04/15 12:03:52 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_extension(char *file, t_game *game)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strcmp(file + len - 4, ".ber") != 0)
		error_exit("Map file must have .ber extension", game);
}

static char	*read_file(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	*content;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Cannot open map file", game);
	content = ft_strdup("");
	if (!content)
		error_exit("Malloc failed", game);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(content, line);
		free(content);
		free(line);
		if (!tmp)
			error_exit("Malloc failed", game);
		content = tmp;
		line = get_next_line(fd);
	}
	close(fd);
	return (content);
}

static void	build_grid(char *content, t_game *game)
{
	game->map.grid = ft_split(content, '\n');
	free(content);
	if (!game->map.grid || !game->map.grid[0])
		error_exit("Empty or invalid map", game);
	game->map.rows = 0;
	while (game->map.grid[game->map.rows])
		game->map.rows++;
	game->map.cols = ft_strlen(game->map.grid[0]);
}

void	parse_map(char *file, t_game *game)
{
	char	*content;

	check_extension(file, game);
	content = read_file(file, game);
	if (!content || !*content)
	{
		free(content);
		error_exit("Empty map file", game);
	}
	build_grid(content, game);
}
