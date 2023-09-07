/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:40:38 by baltes-g          #+#    #+#             */
/*   Updated: 2023/06/26 14:32:33 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_join(char *s1, char *s2, int rm)
{
	if (rm == FIRST)
		free(s1);
	else if (rm == SECOND)
		free(s2);
	else if (rm == BOTH)
	{
		free(s1);
		free(s2);
	}
}

char	*ft_strjoin(char *s1, char *s2, int rm)
{
	char	*new;
	int		i;
	char	*ant[2];

	ant[0] = s1;
	ant[1] = s2;
	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (*s1 != '\0')
	{
		new[i] = *s1;
		++i;
		++s1;
	}
	while (*s2 != '\0')
	{
		new[i] = *s2;
		++i;
		++s2;
	}
	new[i] = '\0';
	free_join(ant[0], ant[1], rm);
	return (new);
}
