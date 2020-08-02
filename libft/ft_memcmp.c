/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:45:17 by vflander          #+#    #+#             */
/*   Updated: 2020/05/05 23:45:17 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Function compares the first 'n' bytes (each interpreted as unsigned char)
**	of the memory areas 's1' and 's2'.
**	Returns an integer less than, equal to, or greater than zero if
**	the first 'n' bytes of 's1' is found, respectively, to be less than,
**	to match, or be greater than the first 'n' bytes of 's2'.
**	For a nonzero return value, the sign is determined by the sign of the
**	difference between the first pair of bytes (interpreted as unsigned char)
**	that differ in 's1' and 's2'.
**	If 'n' is zero, the return value is zero.
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	c1;
	char	c2;

	i = 0;
	while (i < n)
	{
		c1 = *((char*)s1 + i);
		c2 = *((char*)s2 + i);
		if (c1 == c2)
			i += 1;
		else if ((c1 < c2) || (c1 > c2))
			return ((unsigned char)c1 - (unsigned char)c2);
	}
	return (0);
}
