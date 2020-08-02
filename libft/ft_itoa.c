/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:06:36 by vflander          #+#    #+#             */
/*   Updated: 2020/05/04 16:06:36 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	find_len(int n)
{
	int		num_len;

	num_len = 1;
	if (INT_MIN == n)
		num_len = 1 + find_len(n / 10);
	if (ft_abs(n) >= 10)
		num_len = 1 + find_len(n / 10);
	if ((-9 <= n) && (n < 0))
		num_len += 1;
	return (num_len);
}

/*
**	Allocates (with malloc(3)) and returns a string representing the integer
**	received as an argument. NULL if the allocation fails
*/

char		*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = find_len(n);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	*(result + len) = '\0';
	if (n < 0)
		*(result) = '-';
	if (0 == n)
		*(result) = '0';
	while (n)
	{
		*(result + len - 1) = ft_abs(n % 10) + '0';
		n /= 10;
		len -= 1;
	}
	return (result);
}
