/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:58:44 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 01:07:48 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_correct(char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (map[x][y] == '1')
		return (0);
	return (1);
}

int	key_hook(int key, t_game *game)
{
	if (key == W || key == A || key == S \
	|| key == D || key == 123 || key == 124)
	{
		if (key == W)
			game->key.w = 1;
		if (key == A)
			game->key.a = 1;
		if (key == S)
			game->key.s = 1;
		if (key == D)
			game->key.d = 1;
		if (key == LEFT)
			game->key.left = 1;
		if (key == RIGHT)
			game->key.right = 1;
	}
	return (SUCCESS);
}

int	key_hook_release(int key, t_game *game)
{
	if (key == W)
		game->key.w = 0;
	if (key == A)
		game->key.a = 0;
	if (key == S)
		game->key.s = 0;
	if (key == D)
		game->key.d = 0;
	if (key == LEFT)
		game->key.left = 0;
	if (key == RIGHT)
		game->key.right = 0;
	if (key == 53)
		clean_exit(game);
	return (SUCCESS);
}

int	mouse_hook(int key, int x, int y, t_game *game)
{
	(void) x;
	(void) y;
	if (key == 1)
		game->key.left = 1;
	if (key == 2)
		game->key.right = 1;
	return (SUCCESS);
}

int	mouse_hook_release(int key, int x, int y, t_game *game)
{
	(void) x;
	(void) y;
	if (key == 1)
		game->key.left = 0;
	if (key == 2)
		game->key.right = 0;
	return (SUCCESS);
}
