/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:50:48 by baltes-g          #+#    #+#             */
/*   Updated: 2022/12/14 16:14:41 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(t_flags *flags,
					unsigned long long int nb, int *error, char *base)
{
	if (nb >= 16)
	{
		ft_putnbr(flags, nb / 16, error, base);
		nb = nb % 16;
	}
	if (nb < 16)
	{
		if (*error == 1)
			return ;
		(*flags).aux += ft_printchar_printf(*flags, base[nb], error);
		if (*error != 0)
			return ;
	}
}

int	ft_ptoa_printf(t_flags flags, unsigned long long int c, int *error)
{
	flags.aux = 0;
	flags.aux += ft_printstr_printf(flags, "0x", error);
	if (*error == 0)
		ft_putnbr(&flags, c, error, "0123456789abcdef");
	return (flags.aux);
}
