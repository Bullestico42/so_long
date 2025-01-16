/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:11:18 by apiscopo          #+#    #+#             */
/*   Updated: 2024/12/17 17:53:43 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_null(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->winf = NULL;
	game->grid = NULL;
	game->grid_bis = NULL;
	game->height = 0;
	game->length = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->pos_ex = 0;
	game->pos_ey = 0;
	game->coin = 0;
	game->move = 0;
	game->grid_c = 0;
	game->grid_e = 0;
	game->grid_l = 0;
	game->file = 0;
}

int	exit_param(void *param)
{
	(void)param;
	exit(0);
}

int	begin_render(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error, impossible to init mlx");
		return (0);
	}
	game->win = mlx_new_window(game->mlx, game->length * 64,
			game->height * 64 + 32, "so_long");
	if (!game->win)
	{
		ft_printf("Error, impossible to init win");
		return (0);
	}
	game->textures = (t_textures *)malloc(sizeof(t_textures));
	get_images(game);
	render_map(game);
	put_enemy(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2 || argc > 2)
	{
		ft_printf("usage: %s 'map'\n", argv[0]);
		return (0);
	}
	put_null(&game);
	if (!read_map(argv[1], &game))
	{
		ft_printf("Error, Map Invalid !\n");
		free_grid(game.grid);
		return (0);
	}
	if (!begin_render(&game))
	{
		ft_printf("Error, Render impossible !\n");
		free_resources(&game);
		return (0);
	}
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 17, 0, exit_param, NULL);
	mlx_loop(game.mlx);
	free_resources(&game);
	return (1);
}
