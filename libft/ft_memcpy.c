/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:33:54 by vflander          #+#    #+#             */
/*   Updated: 2020/05/05 22:33:54 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Copies 'n' bytes from memory area 'src' to memory area 'dest'. The memory
**	areas must not overlap. Employing  memcpy() with overlapping areas
**	produces undefined behavior. Returns a pointer to 'dest'.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	while (n--)
		*((char*)dest + n) = *((char*)src + n);
	return (dest);
}
