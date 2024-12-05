/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:11:18 by apiscopo          #+#    #+#             */
/*   Updated: 2024/12/05 18:54:00 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	mlx_ptr = mlx_init();
	mlx_new_window(mlx_ptr, 1920, 1080, "so_long");
	mlx_loop(mlx_ptr);
	return (0);
}
