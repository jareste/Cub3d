/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:51:39 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 05:35:51 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	clean_exit(t_game *game)
{
	int	i;

	if (game->map.tex_n)
		free(game->map.tex_n);
	if (game->map.tex_o)
		free(game->map.tex_o);
	if (game->map.tex_s)
		free(game->map.tex_s);
	if (game->map.tex_e)
		free(game->map.tex_e);
	i = -1;
	while (game->map.map[++i])
		free(game->map.map[i]);
	if (game->map.map)
		free(game->map.map);
	if (game->mlx.mlx_win && game->mlx.mlx)
		mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	parse(argc, argv, &game);
	init(&game);
	mlx_hook(game.mlx.mlx_win, 2, (1L << 0), &key_hook, &game);
	mlx_hook(game.mlx.mlx_win, 3, (1L << 0), &key_hook_release, &game);
	mlx_hook(game.mlx.mlx_win, 4, (1L << 0), &mouse_hook, &game);
	mlx_hook(game.mlx.mlx_win, 5, (1L << 0), &mouse_hook_release, &game);
	mlx_hook(game.mlx.mlx_win, 17, 0, &clean_exit, &game);
	render(&game);
	mlx_loop_hook(game.mlx.mlx, render, &game);
	mlx_loop(game.mlx.mlx);
}
