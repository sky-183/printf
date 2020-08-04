/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 20:53:38 by vflander          #+#    #+#             */
/*   Updated: 2020/08/04 15:26:27 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Writes given number in spicified (as a string of digits) base to stdout
**	Returns -1 in case of error (incorrect input)
**	!! Test this all over the place, includeing negative numbers !!
*/

int			ft_atoi_base(int n, char *string_of_digits)
{
	int		base;
	size_t	i;
	size_t	j;

	if (string_of_digits == NULL || ft_strlen(string_of_digits) < 1)
		return (-1);
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', 1);
	}
	base = ft_strlen(string_of_digits);
	i = n / base;
	j = n % base;
	if (i > 0)
		ft_atoi_base(i, string_of_digits);
	ft_putchar_fd(string_of_digits[j], 1);
	return (0);
}

/*
**	Writes given number as a hexadecimal value
*/

int			ft_atoi_hex(int n)
{
	return (ft_atoi_base(n, "0123456789ABCDEF"));
}
