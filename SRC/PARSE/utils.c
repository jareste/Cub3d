/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:29:20 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 01:45:46 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_parse(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit (1);
	return (FAILURE);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
}

int	ft_strlen_n(const char *str)
{
	int	len;

	len = 0;
	while (*str != '\0' && *str != ' ')
	{
		++str;
		++len;
	}
	return (len);
}

int	ft_ptrlen(char **str)
{
	int	len;

	len = 0;
	while (str[len] != NULL)
	{
		++len;
	}
	return (len);
}

int	ft_atoi_cub(char *str, int free_args)
{
	int		sum;
	char	*aux;

	aux = str;
	sum = 0;
	if (ft_strlen(str) > 4)
		exit_parse("Number too long in colours");
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + *str - 48;
		++str;
	}
	if (*str != '\0' && *str != '\n')
		exit_parse("Invalid char between numbers");
	if (sum > 256)
		exit_parse("Number too long in colours");
	if (free_args == FIRST)
		free(aux);
	return (sum);
}
