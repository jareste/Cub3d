/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:25:27 by baltes-g          #+#    #+#             */
/*   Updated: 2022/12/14 16:12:05 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(t_flags flags, int nb, int *error, int *aux)
{
	if (nb >= 10)
	{
		ft_putnbr(flags, nb / 10, error, aux);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		if (*error == 1)
			return ;
		(*aux) += ft_printchar_printf(flags, nb + 48, error);
		if (*error == 1)
			return ;
	}
}

int	ft_itoa_printf(t_flags flags, int c, int *error)
{
	int	aux;

	aux = 0;
	if (c == -2147483648)
		return (ft_printstr_printf(flags, "-2147483648", error));
	if (c < 0)
	{
		aux += ft_printchar_printf(flags, '-', error);
		c = -c;
	}
	else if (flags.plus == 1)
		aux += ft_printchar_printf(flags, '+', error);
	else if (flags.space == 1)
		aux += ft_printchar_printf(flags, ' ', error);
	if (*error == 0)
		ft_putnbr(flags, c, error, &aux);
	return (aux);
}
