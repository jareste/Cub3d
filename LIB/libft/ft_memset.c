/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:44:33 by baltes-g          #+#    #+#             */
/*   Updated: 2022/09/14 16:52:35 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((char *)(b + i)) = (unsigned char) c;
		++i;
	}
	return ((char *) b);
}
/*
int	main(void)
{
	char c[50];
	write(1, ft_memset(c, 50, 5), 6);
}*/
