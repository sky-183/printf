/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 00:29:21 by vflander          #+#    #+#             */
/*   Updated: 2020/07/21 01:04:13 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

//TODO: TEST!

/*
**	Count digints, needed to write (unsigned long long int) 'number'
**	in the given (size_t) base.
**	Used for ft_itoa_base function.
**	No error checking.
*/

static size_t		count_numbers(unsigned long long number, size_t base)
{
	size_t		count;

	count = 0;
	while (number)
	{
		number /= base;
		count += 1;
	}
	return (count);
}

/*
**	Returns adress of a string representation of a given number in a given base
**	(up to 16) or NULL if malloc allocation fails.
*/

char			*ft_itoa_base(unsigned long long number, size_t base)
{
	const char	*digits_string;
	char		*result;
	size_t		i;

	if (!number)
		return(ft_strdup("0"));//return NULL or "0"
	digits_string = "0123456789ABCDEF";
	i = count_numbers(number, base);
	if (NULL != (result = malloc(i + 1)))//return NULL in the end on error
	{
		*(result + i) = '\0';
		while (i)
		{
			i -= 1;
			*(result + i) = *(digits_string + number % base);
			number /= base;
		}
	}
	return (result);
}

/*
**	Returns adress of a string representation of a given number in hexadecimal
**	format or NULL if malloc allocation fails.
*/

char			*ft_itoa_hex(unsigned long long number)
{
	return ft_itoa_base(number, 16);
}
