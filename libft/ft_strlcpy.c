/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 21:40:36 by vflander          #+#    #+#             */
/*   Updated: 2020/05/06 21:40:36 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Copies up to 'size' - 1 characters from the NUL-terminated string 'src'
**	to 'dst', NUL-terminating the result. Return the total length of the
**	string it tried to create (length of 'src').
*/

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (0 == size)
		return (len);
	if (size > len + 1)
		size = len + 1;
	size -= 1;
	*(dst + size) = '\0';
	while (size)
	{
		size -= 1;
		*(dst + size) = *(src + size);
	}
	return (len);
}
