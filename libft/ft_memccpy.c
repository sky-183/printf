/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:49:04 by vflander          #+#    #+#             */
/*   Updated: 2020/05/05 22:49:04 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Copies no more than 'n' bytes from memory area 'src' to memory
**	area 'dest', stopping when the character 'c' is copied. If the memory
**	areas overlap, the results are undefined. The memccpy() function returns
**	a pointer to the next character in 'dest' after 'c', or NULL if 'c' was
**	not found in the first 'n' characters of 'src'.
*/

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		if (*((char *)dest + i) == (char)c)
		{
			dest = ((char *)dest + i + 1);
			return (dest);
		}
		i += 1;
	}
	return (NULL);
}
