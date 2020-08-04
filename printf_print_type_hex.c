/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print_type_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 13:21:31 by vflander          #+#    #+#             */
/*   Updated: 2020/08/04 13:22:25 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Returns length of unsigned int in its hexadecimal representation, including
**	additional zeros for precision or '0' flag and for '0x'.
**	Basically, len of everything except spaces from 'width' mod.
*/

static int		printf_get_number_len_hex(size_t number, t_format_data *f)
{
	int			len;

	len = 1;
	if ((0 == number) && (true == f->mod_precision) && \
		(0 == f->mod_precision_value))
		len = 0;
	while (number / 16)
	{
		number /= 16;
		len += 1;
	}
	if ((f->flag_hash && number && 'p' != f->mod_type) || ('p' == f->mod_type))
		len += 2;
	if (true == f->mod_precision && f->mod_precision_value > len)
		f->misc_num_of_zeros = f->mod_precision_value - len;
	len += f->misc_num_of_zeros;
	if (true == f->flag_zero && !(f->flag_minus))
	{
		f->misc_num_of_zeros = f->mod_width_value - len;
		if (f->misc_num_of_zeros < 0)
			f->misc_num_of_zeros = 0;
		len += f->misc_num_of_zeros;
	}
	return (len);
}

/*
**	Prints given unsigned int to stdout in hexadecimal form.
**	Returns number of bytes written.
*/

static int		printf_putnbr_hex(size_t n, bool capital)
{
	char		*digits;
	char		c;
	int			bytes_written;

	digits = "0123456789abcdef0123456789ABCDEF";
	bytes_written = 0;
	if (n >= 16)
		bytes_written += printf_putnbr_hex(n / 16, capital);
	c = digits[(n % 16) + 16 * capital];
	bytes_written += write(1, &c, 1);
	return (bytes_written);
}

/*
**	Prints hexadecimal representation of unsigned int number with '0x' if
**	needed (but not spaces for width modifier).
**	Returns number of bytes written.
*/

static int		printf_print_type_hex_number(size_t number, t_format_data *f)
{
	int			bytes_written;
	char		mod_type;
	bool		capital;

	mod_type = f->mod_type;
	bytes_written = 0;
	if (true == f->flag_hash && (0 != number) && ('p' != mod_type))
	{
		bytes_written += write(1, "0", 1);
		bytes_written += write(1, &mod_type, 1);
	}
	if ('p' == mod_type)
		bytes_written += write(1, "0x", 2);
	if ('X' == mod_type)
		capital = true;
	else
		capital = false;
	while ((f->misc_num_of_zeros)-- > 0)
		bytes_written += write(1, "0", 1);
	if ((0 == number) && (true == f->mod_precision) && \
		(0 == f->mod_precision_value))
		bytes_written += 0;
	else
		bytes_written += printf_putnbr_hex(number, capital);
	return (bytes_written);
}

/*
**	Print unsigned int-type arguments (x, X, p) as a hexadecimal number.
**	Returns number of bytes written.
*/

int				printf_print_type_hex(va_list *ap, t_format_data *f)
{
	int			bytes_written;
	size_t		number;
	int			tmp;
	int			num_of_spaces;

	if ('p' == f->mod_type)
		number = va_arg(*ap, size_t);
	else
		number = va_arg(*ap, unsigned int);
	num_of_spaces = 0;
	if (((tmp = (f->mod_width_value - printf_get_number_len_hex(number, f))) \
		>= 0) && f->mod_width)
		num_of_spaces = tmp;
	bytes_written = 0;
	if (true == f->flag_minus)
		bytes_written += printf_print_type_hex_number(number, f);
	if (true == f->mod_width)
		while (num_of_spaces)
		{
			bytes_written += write(1, " ", 1);
			num_of_spaces -= 1;
		}
	if (false == f->flag_minus)
		bytes_written += printf_print_type_hex_number(number, f);
	return (bytes_written);
}
