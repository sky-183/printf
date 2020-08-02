/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 20:57:24 by vflander          #+#    #+#             */
/*   Updated: 2020/05/06 20:57:24 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Locates the first occurrence of the null-terminated string 'little'
**	in the string 'big', where not more than 'len' characters are searched.
**	Characters that appear after a ‘\0’ character are not searched.
**	If 'little' is an empty string, 'big' is returned; if 'little' occurs
**	nowhere in 'big', NULL is returned; otherwise a pointer to the first
**	character of the first occurrence of 'little' is returned.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_little;

	len_little = ft_strlen(little);
	if (!len_little)
		return ((char*)big);
	if (len_little > len)
		return (NULL);
	i = 0;
	while (*(big + i) && (i < len - len_little + 1))
	{
		j = 0;
		while (*(big + i + j))
		{
			if (*(big + i + j) != *(little + j))
				break ;
			j += 1;
			if (*(little + j) == '\0')
				return (char*)(big + i);
		}
		i += 1;
	}
	return (NULL);
}
