/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 21:31:02 by vflander          #+#    #+#             */
/*   Updated: 2020/05/06 21:31:02 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Compares only the first (at most) 'n' bytes of two strings 's1' and 's2'.
**	It returns an integer less than, equal to, or greater than zero if 's1'
**	is found, respectively, to be less than, to match, or be greater than 's2'.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((*s1 == *s2) && *s1)
		{
			i += 1;
			s1 += 1;
			s2 += 1;
		}
		else
			return (*((unsigned char*)s1) - *((unsigned char*)s2));
	}
	return (0);
}
