/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:02:16 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 09:23:50 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_render_vars(t_player *pl, t_ray *r, int x)
{
	r->camerax = 2 * x / (float)WIDTH - 1;
	r->raydirx = pl->dirx + pl->planex * r->camerax;
	r->raydiry = pl->diry + pl->planey * r->camerax;
	r->mapx = pl->locx;
	r->mapy = pl->locy;
	r->deltadistx = fabs(1 / r->raydirx);
	r->deltadisty = fabs(1 / r->raydiry);
	r->hit = 0;
	return (SUCCESS);
}

int	find_dist_to_edge(t_player *pl, t_ray *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (pl->locx - r->mapx) * r->deltadistx;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = (r->mapx + 1.0 - pl->locx) * r->deltadistx;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (pl->locy - r->mapy) * r->deltadisty;
	}
	else
	{
		r->stepy = 1;
		r->sidedisty = (r->mapy + 1.0 - pl->locy) * r->deltadisty;
	}
	return (SUCCESS);
}

int	find_collision(t_game *game, t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->sidedistx < r->sidedisty)
		{
			r->sidedistx += r->deltadistx;
			r->mapx += r->stepx;
			r->side = 0;
		}
		else
		{
			r->sidedisty += r->deltadisty;
			r->mapy += r->stepy;
			r->side = 1;
		}
		if (game->map.map[r->mapx][r->mapy] == '1')
			r->hit = 1;
	}
	return (SUCCESS);
}

int	render(t_game *game)
{
	t_render	rend;

	rend.x = 0;
	rend.pl = game->player;
	while (rend.x < WIDTH)
	{
		init_render_vars(&rend.pl, &rend.r, rend.x);
		find_dist_to_edge(&rend.pl, &rend.r);
		find_collision(game, &rend.r);
		rend.r.perpwalldist = compute_dist(&rend.pl, &rend.r);
		draw_vertical(game, &rend, (int)(HEIGHT / rend.r.perpwalldist), \
		compute_xcoord(&rend.pl, &rend.r));
		++rend.x;
	}
	wasd_moves(game);
	rot_moves(game);
	print_2d(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		game->mlx.img.img, 0, 0);
	return (SUCCESS);
}
