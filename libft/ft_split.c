/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:36:25 by vflander          #+#    #+#             */
/*   Updated: 2020/05/05 16:36:25 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates (with malloc(3)) and returns an array of strings obtained
**	by splitting ’s’ using the character ’c’ as a delimiter. The array must be
**	ended by a NULL pointer. NULL if the allocation fails.
*/

static size_t	count_words(char const *s, char c)
{
	size_t		result;
	size_t		len;
	size_t		i;

	result = 0;
	len = 0;
	i = 0;
	while (1)
	{
		len += 1;
		if ((*(s + i) == c) || (*(s + i) == '\0'))
		{
			if (len != 1)
				result += 1;
			len = 0;
		}
		if (*(s + i) == '\0')
			break ;
		i += 1;
	}
	return (result);
}

static int		fill_array(char **array, char const *s, char c)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (1)
	{
		len += 1;
		if ((*(s + i) == c) || (*(s + i) == '\0'))
		{
			if (len != 1)
			{
				*array = ft_substr(s, i - len + 1, len - 1);
				if (*array == NULL)
					return (1);
				array += 1;
			}
			len = 0;
		}
		if (*(s + i) == '\0')
			break ;
		i += 1;
	}
	*array = NULL;
	return (0);
}

static void		free_array(char **array)
{
	while (*array)
	{
		free(*array);
		array += 1;
	}
}

char			**ft_split(char const *s, char c)
{
	char		**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	if (fill_array(result, s, c))
	{
		free_array(result);
		free(result);
		return (NULL);
	}
	return (result);
}
