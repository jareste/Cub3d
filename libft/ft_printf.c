/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:14:22 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 02:20:42 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_flags	getflags(char const *str, int *i)
{
	t_flags	flags;

	flags.space = 0;
	flags.hash = 0;
	flags.plus = 0;
	if (str[*i] == '#')
		flags.hash = 1;
	if (str[*i] == ' ')
		flags.space = 1;
	if (str[*i] == '+')
		flags.plus = 1;
	if (flags.hash == 1 || flags.plus == 1 || flags.space == 1)
		(*i)++;
	return (flags);
}

static int	ft_parse_type(char const *str, va_list args, int *i, int *error)
{
	t_flags	flags;
	int		aux;

	flags = getflags(str, i);
	aux = (*i)++;
	if (str[aux] == 'c')
		return (ft_printchar_printf(flags, va_arg(args, int), error));
	else if (str[aux] == 's')
		return (ft_printstr_printf(flags, va_arg(args, char *), error));
	else if (str[aux] == 'p')
		return (ft_ptoa_printf(flags, va_arg(args, long long int), error));
	else if (str[aux] == 'd')
		return (ft_itoa_printf(flags, va_arg(args, int), error));
	else if (str[aux] == 'i')
		return (ft_itoa_printf(flags, va_arg(args, int), error));
	else if (str[aux] == 'u')
		return (ft_uitoa_printf(flags, va_arg(args, unsigned int), error));
	else if (str[aux] == 'x')
		return (ft_htoa_printf(flags, va_arg(args, unsigned int), error, 0));
	else if (str[aux] == 'X')
		return (ft_htoa_printf(flags, va_arg(args, unsigned int), error, 1));
	else if (str[aux] == '%')
		return (ft_printchar_printf(flags, '%', error));
	*error = 1;
	return (-1);
}

static int	ft_printvar(char const *str, va_list args, int *i, int *error)
{
	int	aux;

	if (str[*i] != '%')
	{
		aux = write(1, &str[*i], 1);
		if (aux == -1)
			*error = 1;
		(*i)++;
		return (1);
	}
	else if (str[*i] == '%')
	{
		(*i)++;
		return (ft_parse_type(str, args, i, error));
	}
	else
	{
		*error = 1;
		write(1, "incomplete format specifier\n", 28);
		return (0);
	}
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		error;
	int		sum;

	error = 0;
	i = 0;
	sum = 0;
	va_start(args, str);
	while (str[i] != '\0' && error != 1)
		sum += ft_printvar(str, args, &i, &error);
	va_end(args);
	if (error == 1)
		return (-1);
	return (sum);
}

/*int	main()
{
	ft_printf("%p\n", 0);
	printf("%p", (void *)0);
	return (0);
}*/