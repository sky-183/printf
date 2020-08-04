/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print_type_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 13:19:22 by vflander          #+#    #+#             */
/*   Updated: 2020/08/04 13:38:06 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Returns length of number, including '-' for negatives and ' ' or '+' for
**	positives (if those flags are specified) and additional zeros for precision
**	or '0' flag.
*/

static int		print_get_number_len_part2(long int number, t_format_data *f, \
				int len)
{
	if (number < 0)
		len += 1;
	else if (f->mod_type != 'u')
		if (f->flag_plus || f->flag_space)
			len += 1;
	if (true == f->flag_zero && !(f->flag_minus))
	{
		f->misc_num_of_zeros = f->mod_width_value - len;
		if (f->misc_num_of_zeros < 0)
			f->misc_num_of_zeros = 0;
		len += f->misc_num_of_zeros;
	}
	return (len);
}

static int		printf_get_number_len(long int number, t_format_data *f)
{
	int			len;
	long int	tmp;

	len = 1;
	if ((0 == number) && (true == f->mod_precision) && \
		(0 == f->mod_precision_value))
		len = 0;
	tmp = number;
	while (tmp / 10)
	{
		tmp /= 10;
		len += 1;
	}
	if (true == f->mod_precision && f->mod_precision_value > len)
	{
		f->misc_num_of_zeros = f->mod_precision_value - len;
		len += f->misc_num_of_zeros;
	}
	return (printf_get_number_len_part2(number, f, len));
}

/*
**	Prints given long int to the stdout.
**	Returns number of bytes written.
*/

static int		printf_putnbr_long(long int n)
{
	char		c;
	int			bytes_written;

	bytes_written = 0;
	if (n >= 10)
		bytes_written += printf_putnbr_long(n / 10);
	c = '0' + n % 10;
	bytes_written += write(1, &c, 1);
	return (bytes_written);
}

/*
**	Prints int (signed or not) number with ' ' or '+' before, if needed.
**	Also prints leading zeros for 'precision' and '0' flag,
**	but not spaces for 'width'.
**	Returns number of bytes written.
*/

static int		printf_print_type_int_number(long int number, t_format_data *f)
{
	int			bytes_written;

	bytes_written = 0;
	if (number >= 0 && (f->mod_type != 'u'))
	{
		if (f->flag_plus)
			bytes_written += write(1, "+", 1);
		else if (f->flag_space)
			bytes_written += write(1, " ", 1);
	}
	if (number < 0)
	{
		bytes_written += write(1, "-", 1);
		number = -number;
	}
	while ((f->misc_num_of_zeros)-- > 0)
		bytes_written += write(1, "0", 1);
	if ((0 == number) && (true == f->mod_precision) && \
		(0 == f->mod_precision_value))
		bytes_written += 0;
	else
		bytes_written += printf_putnbr_long(number);
	return (bytes_written);
}

/*
**	Prints int-type argument (both signed and unsigned)
**	according to flags and specifiers.
**	Returns number of bytes written.
*/

int				printf_print_type_int(va_list *ap, t_format_data *f)
{
	int			bytes_written;
	long int	number;
	int			tmp;
	int			num_of_spaces;

	if ('u' == f->mod_type)
		number = va_arg(*ap, unsigned int);
	else
		number = va_arg(*ap, int);
	num_of_spaces = 0;
	if (((tmp = f->mod_width_value - printf_get_number_len(number, f)) >= 0) \
		&& f->mod_width)
		num_of_spaces = tmp;
	bytes_written = 0;
	if (true == f->flag_minus)
		bytes_written += printf_print_type_int_number(number, f);
	if (true == f->mod_width)
		while (num_of_spaces)
		{
			bytes_written += write(1, " ", 1);
			num_of_spaces -= 1;
		}
	if (false == f->flag_minus)
		bytes_written += printf_print_type_int_number(number, f);
	return (bytes_written);
}
