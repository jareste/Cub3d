/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:14:39 by baltes-g          #+#    #+#             */
/*   Updated: 2022/09/15 18:39:36 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		++str;
		++len;
	}
	return (len);
}
/*
int main(void)
{
	char *a = "sdvfb";
	int b = ft_strlen(a);	
	printf("%d", b);
}*/
