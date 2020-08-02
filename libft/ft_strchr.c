/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 20:31:13 by vflander          #+#    #+#             */
/*   Updated: 2020/05/06 20:31:13 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns a pointer to the first occurrence of the character 'c'
**	in the string 's' or NULL if it's not found. Consider '\0' as a part of
**	the string for this purpose (so terminator character can be valid 'c').
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return (char*)(s);
		s += 1;
	}
	if ((unsigned char)c == '\0')
		return (char*)(s);
	return (NULL);
}
