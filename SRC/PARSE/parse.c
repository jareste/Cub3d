/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:53:45 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 13:57:09 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	aux_read_tex_colours(t_game *game, char *line, int *count)
{
	if (ft_strlen_n(line) == 2)
	{
		read_texture(game, line);
		++*count;
	}
	else if (ft_strlen_n(line) == 1)
	{
		read_colour(game, line);
		++*count;
	}
	else
	{
		exit_parse("Syntax error in map file");
	}
}

int	read_textures_colours(int fd, t_game *game)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line && count < 6)
	{
		while (*line == ' ')
			++line;
		if (*line != '\n' && line && !is_map(line))
			aux_read_tex_colours(game, line, &count);
		free(line);
		if (count < 6)
			line = get_next_line(fd);
	}
	if (count != 6)
		exit_parse("There should be 4 textures and 2 colours before the map");
	return (SUCCESS);
}

int	parse(int argc, char **argv, t_game *game)
{
	int	fd;

	game->player.player = 0;
	if (argc != 2)
		exit_parse("Invalid number of arguments");
	if (ft_strlen(argv[1]) < 5 || ft_strncmp(argv[1] \
	+ ft_strlen(argv[1]) - 4, ".cub", 0xFF))
		exit_parse("File extension must be '.cub'");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_parse("Cannot open map file");
	read_textures_colours(fd, game);
	read_map(fd, game);
	check_map(game, game->map.map, &game->player);
	return (SUCCESS);
}
