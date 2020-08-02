/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 22:23:46 by vflander          #+#    #+#             */
/*   Updated: 2020/05/06 22:23:46 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns a pointer to a new string which is a duplicate of the string 's'
**	or NULL of allocation failed. Memory for the new string is obtained with
**	malloc(3), and can be freed with free(3).
*/

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	i;

	new_str = malloc(ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(new_str + i) = *(s + i);
		i += 1;
	}
	*(new_str + i) = '\0';
	return (new_str);
}
