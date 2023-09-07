/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 00:23:41 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/07 01:06:44 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	do_w(t_game *game)
{
	if (check_correct(game->map.map, game->player.locx + \
	game->player.dirx * SPEED, game->player.locy))
		game->player.locx += game->player.dirx * SPEED;
	if (check_correct(game->map.map, game->player.locx, \
	game->player.locy + game->player.diry * SPEED))
		game->player.locy += game->player.diry * SPEED;
}

static void	do_a(t_game *game)
{
	if (check_correct(game->map.map, game->player.locx - \
	game->player.diry * SPEED, game->player.locy))
		game->player.locx -= game->player.diry * SPEED;
	if (check_correct(game->map.map, game->player.locx, \
	game->player.locy + game->player.dirx * SPEED))
		game->player.locy += game->player.dirx * SPEED;
}

static void	do_s(t_game *game)
{
	if (check_correct(game->map.map, game->player.locx - \
	game->player.dirx * SPEED, game->player.locy))
		game->player.locx -= game->player.dirx * SPEED;
	if (check_correct(game->map.map, game->player.locx, \
	game->player.locy - game->player.diry * SPEED))
		game->player.locy -= game->player.diry * SPEED;
}

static void	do_d(t_game *game)
{
	if (check_correct(game->map.map, game->player.locx + \
	game->player.diry * SPEED, game->player.locy))
		game->player.locx += game->player.diry * SPEED;
	if (check_correct(game->map.map, game->player.locx, \
	game->player.locy - game->player.dirx * SPEED))
		game->player.locy -= game->player.dirx * SPEED;
}

int	wasd_moves(t_game *game)
{
	if (game->key.w)
		do_w(game);
	if (game->key.a)
		do_a(game);
	if (game->key.s)
		do_s(game);
	if (game->key.d)
		do_d(game);
	return (SUCCESS);
}
