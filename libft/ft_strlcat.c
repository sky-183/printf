/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 21:54:23 by vflander          #+#    #+#             */
/*   Updated: 2020/05/06 21:54:23 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Appends the NUL-terminated string 'src' to the end of 'dst'. It will
**	append at most 'size' - strlen(dst) - 1 bytes, NUL-terminating the result.
**	Return the total length of the string it tried to create (the initial
**	length of 'dst' plus the length of 'src'). While this may seem somewhat
**	confusing, it was done to make truncation detection simple.
**	If strlcat() traverses 'size' characters without finding a '\0', the
**	length of the string is considered to be 'size' and the destination
**	string will not be nul-terminated (since there was no space for the nul).
**	this keeps strlcat() from running off the end of a string. In practice this
**	should not happen (as it means that either size is incorrect or that dst is
**	not a proper “c” string). The check exists to prevent potential security
**	problems in incorrect code.
*/

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	len_src = ft_strlen(src);
	if (0 == size)
		return (len_src);
	i = 0;
	while (*(dst + i) && (i < size))
		i += 1;
	len_dst = i;
	while ((i + 1 < size) && *(src + i - len_dst))
	{
		*(dst + i) = *(src + i - len_dst);
		i += 1;
	}
	if (i > len_dst)
		*(dst + i) = '\0';
	return (len_src + len_dst);
}
