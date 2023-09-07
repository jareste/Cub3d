/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_setup_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 02:00:44 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/07 05:45:01 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup_n(t_player *player)
{
	player->dirx = -1;
	player->diry = 0;
	player->planex = 0;
	player->planey = 0.66;
}

static void	setup_s(t_player *player)
{
	player->dirx = 1;
	player->diry = 0;
	player->planex = 0;
	player->planey = -0.66;
}

static void	setup_e(t_player *player)
{
	player->dirx = 0;
	player->diry = -1;
	player->planex = -0.66;
	player->planey = 0;
}

static void	setup_w(t_player *player)
{
	player->dirx = 0;
	player->diry = 1;
	player->planex = 0.66;
	player->planey = 0;
}

int	setup_pl(t_player *player, char coord, int col, int row)
{
	player->locx = row + 0.5;
	player->locy = col + 0.5;
	player->player = 1;
	if (coord == 'N')
		setup_n(player);
	else if (coord == 'S')
		setup_s(player);
	else if (coord == 'E')
		setup_e(player);
	else if (coord == 'W')
		setup_w(player);
	else
		return (exit_parse("Error assigning the orentation"));
	return (SUCCESS);
}
