/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:29:29 by vflander          #+#    #+#             */
/*   Updated: 2020/05/05 23:29:29 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Scans the initial 'n' bytes of the memory area pointed to by 's' for the
**	first instance of 'c'. Both 'c' and the bytes of the memory area pointed
**	to by 's' are interpreted as unsigned char. Return a pointer to the
**	matching byte or NULL if the character does not occur
**	in the given memory area.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char*)s + i) == (unsigned char)c)
			return (void*)((unsigned char*)s + i);
		i += 1;
	}
	return (NULL);
}
