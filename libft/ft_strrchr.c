/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 20:42:01 by vflander          #+#    #+#             */
/*   Updated: 2020/05/06 20:42:01 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns a pointer to the last occurrence of the character 'c'
**	in the string 's' or NULL if it's not found. Consider '\0' as a part of
**	the string for this purpose (so terminator character can be valid 'c').
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	size_t	i;

	i = 0;
	last = NULL;
	while (*(s + i))
	{
		if (*(s + i) == (unsigned char)c)
			last = (char*)s + i;
		i += 1;
	}
	if ((unsigned char)c == '\0')
		return ((char*)s + i);
	return (last);
}
