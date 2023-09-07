/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:08:24 by baltes-g          #+#    #+#             */
/*   Updated: 2022/09/22 18:11:26 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trobat(char *src, char *to_find, int i, unsigned int len)
{
	while (*to_find != '\0')
	{
		if (*to_find == *src)
		{
			++src;
			++to_find;
		}
		else
		{
			return (0);
		}
		++i;
	}
	if ((unsigned int)i > len)
		return (0);
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		b;
	size_t	i;

	i = 0;
	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	while (*haystack != '\0' && i < len)
	{
		b = trobat((char *)haystack, (char *)needle, (int)i, (unsigned int)len);
		if (b == 0)
		{
			++haystack;
		}
		else
		{
			return ((char *)haystack);
		}
		++i;
	}
	return (NULL);
}
