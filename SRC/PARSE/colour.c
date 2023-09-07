/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:06:50 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 02:08:10 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_colour(t_game *game, char *line)
{
	char	**split;

	split = ft_split(line, " ,");
	if (!split)
		exit_parse("Malloc error");
	if (ft_ptrlen(split) != 4)
	{
		exit_parse("Problems reading a line in the map file");
	}
	if (line[0] == 'C')
	{
		game->map.ceiling.r = ft_atoi_cub(split[1], NO);
		game->map.ceiling.g = ft_atoi_cub(split[2], NO);
		game->map.ceiling.b = ft_atoi_cub(split[3], NO);
	}
	else if (line[0] == 'F')
	{
		game->map.floor.r = ft_atoi_cub(split[1], NO);
		game->map.floor.g = ft_atoi_cub(split[2], NO);
		game->map.floor.b = ft_atoi_cub(split[3], NO);
	}
	else
		exit_parse("Invalid identifier for colour");
	free_split(split);
	return (SUCCESS);
}
