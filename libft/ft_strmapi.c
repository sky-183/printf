/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:43:17 by vflander          #+#    #+#             */
/*   Updated: 2020/05/04 18:43:17 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Applies the function ’f’ to each character of the string ’s’ to create
**	a new string (with malloc(3)) resulting from successive applications of ’f’
**	Returns NULL of the allocation fails
**	PS: 'f' gets current char index (cast from size_t) and the char itself
*/

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;
	size_t	len;

	if (!f || !s)
		return (NULL);
	len = ft_strlen(s);
	result = (char*)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(result + i) = (*f)(i, *(s + i));
		i += 1;
	}
	*(result + len) = '\0';
	return (result);
}
