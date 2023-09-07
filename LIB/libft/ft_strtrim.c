/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:50:23 by baltes-g          #+#    #+#             */
/*   Updated: 2023/06/26 12:43:01 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_start(char const *s1, char const *set)
{
	int	len;
	int	i;
	int	encara;

	encara = 1;
	len = ft_strlen(s1);
	i = 0;
	while (i < len && encara)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			encara = 0;
		else
			i++;
	}
	return (i);
}

static int	count_end(const char *s1, const char *set)
{
	int	len;
	int	i;
	int	encara;

	encara = 1;
	len = ft_strlen(s1);
	i = 0;
	while (i < len && encara)
	{
		if (ft_strchr(set, s1[len - i - 1]) == NULL)
			encara = 0;
		else
			i++;
	}
	return (len - i);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		start;
	int		end;
	char	*new;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1, NO));
	start = count_start(s1, set);
	end = count_end(s1, set);
	if (start >= end)
		return (ft_strdup("", NO));
	new = malloc(sizeof(char) * (end - start + 1));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1 + start, end - start + 1);
	return (new);
}
