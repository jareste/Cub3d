/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:06:36 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 02:20:13 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	sum;

	sum = 0;
	if (n < 0)
		sum++;
	while (n != 0)
	{
		++sum;
		n /= 10;
	}
	return (sum);
}

static int	absolut(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static char	*especialet(void)
{
	char	*zero;

	zero = malloc(2);
	if (!zero)
		return (NULL);
	zero[0] = 48;
	zero[1] = '\0';
	return (zero);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		i;
	int		len;

	len = intlen(n);
	i = 1;
	if (n == 0)
		return (especialet());
	new = malloc(sizeof(char) * (len +1));
	if (!new)
		return (NULL);
	if (n < 0)
	{
		*new = '-';
	}
	while (n != 0)
	{
		new[len - i] = absolut(n % 10) + 48;
		n /= 10;
		++i;
	}
	new[len] = '\0';
	return (new);
}
