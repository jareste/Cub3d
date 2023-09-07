/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:07:32 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 01:46:22 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_texture(t_game *game, char *line)
{
	char	**split;

	split = ft_split(line, " ");
	if (!split)
		exit_parse("Malloc error");
	if (ft_ptrlen(split) != 2)
	{
		exit_parse("Problems reading a line in the map file");
	}
	if (line[0] == 'N' && line[1] == 'O')
		game->map.tex_n = ft_strdup(split[1], NO);
	else if (line[0] == 'S' && line[1] == 'O')
		game->map.tex_s = ft_strdup(split[1], NO);
	else if (line[0] == 'E' && line[1] == 'A')
		game->map.tex_e = ft_strdup(split[1], NO);
	else if (line[0] == 'W' && line[1] == 'E')
		game->map.tex_o = ft_strdup(split[1], NO);
	else
		exit_parse("Invalid identifier for texture");
	free_split(split);
	return (SUCCESS);
}
