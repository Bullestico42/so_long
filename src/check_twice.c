/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_twice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:28:10 by apiscopo          #+#    #+#             */
/*   Updated: 2024/12/16 02:13:57 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_flood(int fd, int n_lines, t_game *game, char *file)
{
	close(fd);
	fd = open(file, O_RDONLY);
	if (!fill_grid_bis(fd, n_lines, game))
		return (0);
	flood_fill(game, game->player_x, game->player_y);
	if (game->coin != game->grid_c || game->grid_e == 0 || game->grid_e > 4)
	{
		free_grid(game->grid_bis);
		return (0);
	}
	return (1);
}

int	fill_grid_bis(int fd, int n_lines, t_game *game)
{
	char	*line;
	int		i;

	game->grid_bis = (char **)malloc(sizeof(char *) * (n_lines + 1));
	if (!game->grid_bis)
		return (0);
	i = 0;
	while (i < n_lines)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		game->grid_bis[i] = ft_strdup(line);
		free(line);
		if (!game->grid_bis[i])
			return (0);
		i++;
	}
	game->grid_bis[i] = NULL;
	return (1);
}

int	check_coin(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			if (game->grid[y][x] == 'C')
				game->coin++;
			x++;
		}
		y++;
	}
	return (game->coin);
}
