/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 04:22:39 by apiscopo          #+#    #+#             */
/*   Updated: 2024/12/13 21:23:00 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_double(t_game *game)
{
	int	count;
	int	x;
	int	y;

	x = 0;
	y = 0;
	count = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			if (game->grid[y][x] == 'P' || game->grid[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	if (count > 2 || count < 2)
		return (0);
	return (1);
}

int	check_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			if (game->grid[y][x] != '1' && game->grid[y][x] != 'C'
				&& game->grid[y][x] != 'E' && game->grid[y][x] != '0'
				&& game->grid[y][x] != 'P' && game->grid[y][x] != '\n'
				&& game->grid[y][x] != 'L')
				return (0);
			x++;
		}
		y++;
	}
	game->height = y;
	game->length = x;
	return (1);
}

int	check_wall(t_game *game)
{
	int	j;
	int	i;

	j = 0;
	i = 1;
	while (game->grid[game->height - 1][j])
	{
		if (game->grid[0][j] != '1' || game->grid[game->height - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < (game->height - 1))
	{
		if (game->grid[i][0] != '1' || game->grid[i][game->length - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	get_line_length(char *line)
{
	int	size;

	size = 0;
	size = ft_strlen(line);
	if (size > 0 && line[size - 1] == '\n')
		size--;
	return (size);
}

int	size_map(t_game *game)
{
	int	i;
	int	len;
	int	next_len;

	i = 0;
	len = 0;
	next_len = 0;
	len = get_line_length(game->grid[0]);
	if (!len)
		return (0);
	while (game->grid[i + 1])
	{
		next_len = get_line_length(game->grid[i + 1]);
		if (len != next_len)
			return (0);
		i++;
	}
	return (1);
}
