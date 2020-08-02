/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 13:01:39 by vflander          #+#    #+#             */
/*   Updated: 2020/05/05 13:01:39 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	refine_len(unsigned int start, size_t len, const char *s)
{
	size_t		i;

	i = 1;
	while (i <= len)
	{
		if (*(s + start + i) == '\0')
		{
			len = i;
			return (len);
		}
		i += 1;
	}
	return (len);
}

/*
**	Allocates (with malloc(3)) and returns a substring from the string ’s’.
**	The substring begins at index ’start’ and is of maximum size ’len’.
**	Returns empty string ("") if index out of range,
**	NULL if allocation fails or 'start' overflow.
*/

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*result;

	if (!s || (start + len < start))
		return (NULL);
	i = 0;
	while (i <= start)
	{
		if (*(s + i) == '\0')
			return (ft_strdup(""));
		i += 1;
	}
	len = refine_len(start, len, s);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (!(*(s + start + i)))
			break ;
		*(result + i) = *(s + start + i);
		i += 1;
	}
	*(result + i) = '\0';
	return (result);
}
