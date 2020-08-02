/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:01:06 by vflander          #+#    #+#             */
/*   Updated: 2020/05/05 14:01:06 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates (with malloc(3)) and returns a new string, which is the result
**	of the concatenation of ’s1’ and ’s2’, if both strings are valid (not NULL)
**	Return NULL if the allocation fails	or both string is NULL.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	len_s1;
	unsigned int	len_s2;
	unsigned int	i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = malloc(len_s1 + len_s2 + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		*(result + i) = *(s1 + i);
		i += 1;
	}
	while (i <= len_s1 + len_s2)
	{
		*(result + i) = *(s2 + i - len_s1);
		i += 1;
	}
	return (result);
}
