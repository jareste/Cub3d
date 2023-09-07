/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:35:57 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 02:21:18 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0' && *str != '\n')
	{
		++str;
		++len;
	}
	return (len);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup_gnl(char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) *(ft_strlen(s1) + 1));
	if (!new)
		return (NULL);
	while (*s1 != '\0')
	{
		new[i] = *s1;
		++s1;
		++i;
	}
	if (*s1 == '\n')
		new[i] = *s1;
	else
	{
		new[i] = '\0';
	}
	return (new);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*aux;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	aux = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!aux)
		return (clean(s1));
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			aux[i] = s1[i];
	while (s2[j] != '\0')
		aux[i++] = s2[j++];
	aux[i] = '\0';
	free(s1);
	return (aux);
}
