/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:54:19 by baltes-g          #+#    #+#             */
/*   Updated: 2022/12/14 16:12:19 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(t_flags flags, unsigned int nb, int *error, int *aux)
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
		*aux += ft_printchar_printf(flags, nb + 48, error);
		if (*error == 1)
			return ;
	}
}

int	ft_uitoa_printf(t_flags flags, unsigned int c, int *error)
{
	int	aux;

	aux = 0;
	ft_putnbr(flags, c, error, &aux);
	return (aux);
}
