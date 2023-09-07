/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 01:07:05 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/07 01:07:40 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	aux_rot_left(t_game *game, float olddirx, float oldplanex)
{
	game->player.dirx = game->player.dirx * cos(TURN) - \
	game->player.diry * sin(TURN);
	game->player.diry = olddirx * sin(TURN) + \
	game->player.diry * cos(TURN);
	game->player.planex = game->player.planex * \
	cos(TURN) - game->player.planey * sin(TURN);
	game->player.planey = oldplanex * sin(TURN) + \
	game->player.planey * cos(TURN);
}

static void	aux_rot_right(t_game *game, float olddirx, float oldplanex)
{
	game->player.dirx = game->player.dirx * cos(-TURN) - \
	game->player.diry * sin(-TURN);
	game->player.diry = olddirx * sin(-TURN) + \
	game->player.diry * cos(-TURN);
	game->player.planex = game->player.planex * \
	cos(-TURN) - game->player.planey * sin(-TURN);
	game->player.planey = oldplanex * sin(-TURN) \
	+ game->player.planey * cos(-TURN);
}

int	rot_moves(t_game *game)
{
	float	olddirx;
	float	oldplanex;

	olddirx = game->player.dirx;
	oldplanex = game->player.planex;
	if (game->key.left)
		aux_rot_left(game, olddirx, oldplanex);
	if (game->key.right)
		aux_rot_right(game, olddirx, oldplanex);
	return (SUCCESS);
}
