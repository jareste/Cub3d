/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:42:26 by baltes-g          #+#    #+#             */
/*   Updated: 2022/09/21 15:31:43 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;

	x = 0;
	while (x < n)
	{
		if (*((unsigned char *) s) == (unsigned char) c)
			return ((void *)s);
		++s;
		++x;
	}
	return (NULL);
}
