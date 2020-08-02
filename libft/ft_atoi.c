/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:59:38 by vflander          #+#    #+#             */
/*   Updated: 2020/05/05 20:59:38 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns integer value of entered string if it can be interpreted as
**	a number or first part of the string, which can be interpreted that way.
**	Returns 0 in all other cases.
*/

int		ft_atoi(const char *nptr)
{
	int				sign;
	long int		result;

	sign = 1;
	result = 0;
	while ('\n' == *nptr || '\t' == *nptr || '\r' == *nptr || \
			'\f' == *nptr || '\v' == *nptr || ' ' == *nptr)
		nptr++;
	if ('+' == *nptr)
		if (*(nptr + 1) != '-')
			nptr++;
	if ('-' == *nptr)
	{
		sign = -1;
		nptr++;
	}
	while (*nptr <= '9' && *nptr >= '0')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(result * sign));
}
