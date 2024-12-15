/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:28:17 by apiscopo          #+#    #+#             */
/*   Updated: 2024/12/15 22:32:15 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_fill(t_game *game)
{
	if (game->textures->coinf)
		mlx_destroy_image(game->mlx, game->textures->coinf);
	if (game->textures->prefill)
		mlx_destroy_image(game->mlx, game->textures->prefill);
	if (game->winf)
		mlx_destroy_window(game->mlx, game->winf);
	free_grid(game->grid_bis);
}

void	get_images_fill(t_game *game)
{
	int	width;
	int	height;

	game->textures->fill = mlx_xpm_file_to_image(game->mlx, "textures/fill.xpm",
			&width, &height);
	game->textures->coinf = mlx_xpm_file_to_image(game->mlx,
			"textures/coinf.xpm", &width, &height);
	game->textures->prefill = mlx_xpm_file_to_image(game->mlx,
			"textures/prefill.xpm", &width, &height);
	game->textures->lava = mlx_xpm_file_to_image(game->mlx,
			"textures/lava.xpm", &width, &height);
}

void	print_fill(t_game *game)
{
	int	x;
	int	y;

	usleep(20000);
	y = 0;
	while (game->grid_bis[y])
	{
		x = 0;
		while (game->grid_bis[y][x])
		{
			if (game->grid_bis[y][x] == 'T')
				mlx_put_image_to_window(game->mlx, game->winf,
					game->textures->coinf, x * 64, y * 64);
			if (game->grid_bis[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->winf,
					game->textures->floor, x * 64, y * 64);
			x++;
		}
		y++;
	}
	print_fill_bis(game);
}

void	print_fill_bis(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid_bis[y][x])
		{
			if (game->grid_bis[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->winf,
					game->textures->wall, x * 64, y * 64);
			if (game->grid_bis[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->winf,
					game->textures->exit, x * 64, y * 64);
			if (game->grid_bis[y][x] == 'L')
				mlx_put_image_to_window(game->mlx, game->winf,
					game->textures->lava, x * 64, y * 64);
			x++;
		}
		y++;
	}
	print_fill_three(game);
}

void	print_fill_three(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->grid_bis[y])
	{
		x = 0;
		while (game->grid_bis[y][x])
		{
			if (game->grid_bis[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->winf,
					game->textures->collectible, x * 64, y * 64);
			else if (game->grid_bis[y][x] == 'F')
			{
				mlx_put_image_to_window(game->mlx, game->winf,
					game->textures->prefill, x * 64, y * 64);
				usleep(15000);
				game->grid_bis[y][x] = 'Z';
				mlx_put_image_to_window(game->mlx, game->winf,
					game->textures->fill, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}
