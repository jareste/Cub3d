/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:39:13 by baltes-g          #+#    #+#             */
/*   Updated: 2022/09/21 12:05:21 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
	{
		return (0);
	}
	if (n == 1)
	{
		return (*((unsigned char *) s1) - *((unsigned char *) s2));
	}
	else if (*((unsigned char *) s1) == *((unsigned char *) s2))
	{
		++s1;
		++s2;
		return (ft_memcmp(s1, s2, n - 1));
	}
	else
	{
		return ((*(unsigned char *) s1) - *((unsigned char *) s2));
	}
}
