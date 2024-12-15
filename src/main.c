/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:11:18 by apiscopo          #+#    #+#             */
/*   Updated: 2024/12/15 19:29:55 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_param(void *param)
{
	(void)param;
	exit(0);
}

int	begin_check(char *file, t_game *game)
{
	if (!read_map(file, game))
		return (0);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error, impossible to init mlx");
		return (0);
	}
	game->win = mlx_new_window(game->mlx, game->length * 64,
			game->height * 64 + 32, "so_long");
	game->winf = mlx_new_window(game->mlx, game->length * 64, game->height * 64,
			"Fill");
	game->textures = (t_textures *)malloc(sizeof(t_textures));
	get_images_fill(game);
	get_images(game);
	render_map(game);
	put_enemy(game);
	flood_fill(game, game->player_x, game->player_y);
	if (game->coin != game->grid_c || game->grid_e == 0 || game->grid_e > 4
		|| game->grid_l > 0)
		return (0);
	free_fill(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2 || argc > 2)
		return (0);
	if (!begin_check(argv[1], &game))
	{
		ft_printf("Error, Map Invalid !\n");
		free_resources(&game);
		return (0);
	}
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 17, 0, exit_param, NULL);
	mlx_loop(game.mlx);
	free_resources(&game);
	return (1);
}
