/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:23:36 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 13:30:59 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_color(t_game *game, int color)
{
	if (game->map.ceiling.r > 210 && game->map.ceiling.g > 210 && \
	game->map.ceiling.b > 210 && color == 0x00ffffff)
		color = 0x00ff00ff;
	if (game->map.ceiling.r < 60 && game->map.ceiling.g < 60 && \
	game->map.ceiling.b < 60 && color == 0x00000000)
		color = 0x0000ffff;
	return (color);
}

static void	aux_print_2d(t_game *game, int x, int y, int color)
{
	int	j;
	int	k;
	int	size;

	size = 8;
	color = validate_color(game, color);
	if (game->map.n_rows * game->map.n_cols > 1500)
		size = 4;
	j = 0;
	while (j < size)
	{
		k = 0;
		while (k < size)
		{
			my_pixel_put(&game->mlx.img, \
			k + (x * size) + 10, j + (y * size) + 10, color);
			k++;
		}
		j++;
	}
}

void	print_2d(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.n_rows)
	{
		if (!game->map.map[y])
			break ;
		x = 0;
		while (x < game->map.n_cols)
		{
			if (game->map.map[y][x] == '1')
				aux_print_2d(game, x, y, 0x00ffffff);
			if (game->map.map[y][x] == 'N' || game->map.map[y][x] == 'W'\
			|| game->map.map[y][x] == 'E' || game->map.map[y][x] == 'S')
				aux_print_2d(game, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}
