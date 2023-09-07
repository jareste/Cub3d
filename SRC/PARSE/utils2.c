/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 01:44:23 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/07 05:48:12 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*create_string(t_game *game, char c, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(size);
	if (!str)
		clean_exit(game);
	while (i < size -1)
	{
		str[i] = c;
		++i;
	}
	str[i] = '\0';
	return (str);
}

void	dfs(t_map *m, t_check_map *ch_m, int i, int j)
{
	if (i < 0 || j < 0 || i >= m->n_rows \
	|| j > m->n_cols || m->map[i][j] == '-')
	{
		ch_m->found = 1;
		return ;
	}
	if (ch_m->visited[i * m->n_cols + j] == '1' || \
	m->map[i][j] == '1')
		return ;
	ch_m->visited[i * m->n_cols + j] = '1';
	dfs(m, ch_m, i + 1, j);
	dfs(m, ch_m, i, j +1);
	dfs(m, ch_m, i, j + 1);
	dfs(m, ch_m, i, j - 1);
}
