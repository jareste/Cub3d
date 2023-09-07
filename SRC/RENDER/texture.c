/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:17:05 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 01:10:48 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	choose_text(t_ray *r)
{
	int	t;

	if (r->side == 0 && r->raydirx < 0)
		t = 0;
	else if (r->side == 0 && r->raydirx > 0)
		t = 1;
	else if (r->side == 1 && r->raydiry > 0)
		t = 2;
	else
		t = 3;
	return (t);
}

int	compute_xcoord(t_player *pl, t_ray *r)
{
	float	xcoord;

	if (r->side == 0)
		xcoord = pl->locy + r->perpwalldist * r->raydiry;
	else
		xcoord = pl->locx + r->perpwalldist * r->raydirx;
	xcoord = xcoord - floor(xcoord);
	return ((int)(xcoord * 64));
}

float	compute_dist(t_player *pl, t_ray *r)
{
	if (r->side == 0)
		return ((r->mapx - pl->locx + (1 - r->stepx) / 2) / r->raydirx);
	else
		return ((r->mapy - pl->locy + (1 - r->stepy) / 2) / r->raydiry);
}
