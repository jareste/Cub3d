/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:37:04 by baltes-g          #+#    #+#             */
/*   Updated: 2022/09/28 11:38:49 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!(*lst))
		(*lst) = new;
	else
	{
		aux = *lst;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = new;
	}
}
