/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:19:23 by baltes-g          #+#    #+#             */
/*   Updated: 2022/09/21 13:05:33 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	else if (dst < src)
		return (ft_memcpy(dst, src, len));
	else if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			--i;
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
		return (dst);
	}
	else
		return (dst);
}
