/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:59:04 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 02:20:53 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	lendest;
	size_t	lensrc;
	size_t	copiat;

	lendest = 0;
	while (dest[lendest] != '\0')
	{
		++lendest;
	}
	lensrc = 0;
	while (src[lensrc] != '\0')
	{
		++lensrc;
	}
	if (size <= lendest)
		return (size + lensrc);
	copiat = 0;
	while (src[copiat] != '\0' && lendest + copiat + 1 < size)
	{
		dest[lendest + copiat] = src[copiat];
		++copiat;
	}
	dest[lendest + copiat] = '\0';
	return (lendest + lensrc);
}
/*int main(void) {

  char dst[] = "1234";
  char src[] = "ABCD";

  printf ("// Retourn %d\n", ft_strlcat(dst, src, 2));
  printf ("// dst = %s\n", dst);
  printf ("// src = %s\n", src);
}*/
