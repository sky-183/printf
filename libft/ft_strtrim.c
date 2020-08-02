/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 15:30:40 by vflander          #+#    #+#             */
/*   Updated: 2020/05/05 15:30:40 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_in_set(char const c, char const *set)
{
	size_t		i;

	i = 0;
	while (*(set + i))
	{
		if (c == *(set + i))
			return (1);
		i += 1;
	}
	return (0);
}

static size_t	get_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (*(s1 + start))
	{
		if (is_in_set(*(s1 + start), set))
			start += 1;
		else
			break ;
	}
	return (start);
}

static size_t	get_end(char const *s1, size_t start, char const *set)
{
	size_t	end;

	if (!*s1)
		end = 0;
	else
		end = ft_strlen(s1) - 1;
	while (end > start)
	{
		if (is_in_set(*(s1 + end), set))
			end -= 1;
		else
			break ;
	}
	return (end);
}

/*
**	Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
**	specified in ’set’ removed from the beginning and the end of the string.
**	Returns NULL if the allocation fails or any string is not valid.
*/

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	size_t		start;
	size_t		end;
	size_t		i;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, start, set);
	result = malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (NULL);
	i = 0;
	while ((start + i) <= end)
	{
		*(result + i) = *(s1 + start + i);
		i += 1;
	}
	*(result + i) = '\0';
	return (result);
}
