/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:29:16 by baltes-g          #+#    #+#             */
/*   Updated: 2023/08/31 18:03:41 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*clean(char *to_clean)
{
	free(to_clean);
	return (NULL);
}

char	*read_from_file(int fd, char *accumulative)
{
	char	*buffer;
	int		aux;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (clean(accumulative));
	aux = BUFFER_SIZE;
	while (aux == BUFFER_SIZE && ft_strchr_gnl(accumulative, '\n') == NULL)
	{
		aux = read(fd, buffer, BUFFER_SIZE);
		if (aux == -1)
		{
			free(accumulative);
			return (clean(buffer));
		}
		buffer[aux] = '\0';
		if (aux != 0)
			accumulative = ft_strjoin_gnl(accumulative, buffer);
		if (!accumulative)
			aux = 0;
	}
	free(buffer);
	return (accumulative);
}

char	*next_acc(char *accumulative)
{
	char	*aux;

	aux = ft_strchr_gnl(accumulative, '\n');
	if (aux != NULL && *aux == '\n')
	{
		++aux;
		aux = ft_strdup_gnl(aux);
		if (!aux)
		{
			return (clean(accumulative));
		}
		free(accumulative);
		return (aux);
	}
	free(accumulative);
	return (NULL);
}

char	*read_from_acc(char *s1)
{
	char	*new;
	int		i;

	i = 0;
	if (!(*s1))
		return (NULL);
	new = malloc(sizeof(char) *(ft_strlen_gnl(s1) + 1));
	if (!new)
		return (NULL);
	while (*s1 != '\0' && *s1 != '\n')
	{
		new[i] = *s1;
		++s1;
		++i;
	}
	new[i] = '\0';
	if (*s1 == '\n')
	{
		new = ft_strjoin_gnl(new, "\n");
		if (!new)
			return (NULL);
		new[i + 1] = '\0';
	}
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*accumulative[4096];
	char		*aux_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	accumulative[fd] = read_from_file(fd, accumulative[fd]);
	if (!accumulative[fd])
	{
		free(accumulative[fd]);
		accumulative[fd] = NULL;
		return (NULL);
	}
	aux_line = read_from_acc(accumulative[fd]);
	if (!aux_line)
	{
		free(accumulative[fd]);
		accumulative[fd] = NULL;
		return (NULL);
	}
	accumulative[fd] = next_acc(accumulative[fd]);
	return (aux_line);
}
