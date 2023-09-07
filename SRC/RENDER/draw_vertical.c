/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:00:57 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 01:22:39 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_vertical(t_game *game, t_render *rend, int height, int x_tex)
{
	int		i;
	float	step;
	float	pos_img;
	t_image	*img;
	t_image	*tex;

	tex = &game->mlx.textures[choose_text(&rend->r)];
	img = &game->mlx.img;
	i = 0;
	step = (float)64 / height;
	if (height >= HEIGHT)
		pos_img = step * (height - HEIGHT) / 2;
	else
		pos_img = 0;
	while (i < (HEIGHT / 2 - height / 2))
		my_pixel_put(img, rend->x, i++, c2int(&game->map.ceiling));
	while (i < HEIGHT && i < (HEIGHT / 2 + height / 2))
	{
		my_pixel_put(img, rend->x, i, my_pixel_get(tex, x_tex, (int)pos_img));
		pos_img += step;
		++i;
	}
	while (i < HEIGHT)
		my_pixel_put(img, rend->x, i++, c2int(&game->map.floor));
	return (SUCCESS);
}
