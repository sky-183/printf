/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:15:29 by vflander          #+#    #+#             */
/*   Updated: 2020/05/05 23:15:29 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Copies 'n' bytes from memory area 'src' to memory area 'dest'. The memory
**	areas may overlap: copying takes place as though the bytes in 'src' are
**	first copied into a temporary array that does not overlap 'src' or 'dest',
**	and the bytes are then copied from the temporary array to 'dest'.
**	Returns a pointer to 'dest'.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*char_src;
	char	*char_dest;

	if (!dest && !src)
		return (NULL);
	i = 0;
	char_src = (char *)src;
	char_dest = (char *)dest;
	if (char_dest > char_src)
		while (i < n)
		{
			*(char_dest + n - i - 1) = *(char_src + n - i - 1);
			i += 1;
		}
	else
		while (i < n)
		{
			*(char_dest + i) = *(char_src + i);
			i += 1;
		}
	return (dest);
}
