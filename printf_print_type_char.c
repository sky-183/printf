/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print_type_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 13:14:26 by vflander          #+#    #+#             */
/*   Updated: 2020/08/04 13:17:07 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Prints char-type argument according to flags and specifiers.
**	Returns number of bytes written.
*/

int			printf_print_type_char(va_list *ap, t_format_data *f)
{
	int		bytes_written;
	int		this_char;
	int		i;

	bytes_written = 0;
	i = 1;
	if ('%' == f->mod_type)
		this_char = f->mod_type;
	else
		this_char = (unsigned char)va_arg(*ap, int);
	if (true == f->flag_minus)
		bytes_written += write(1, &this_char, 1);
	if (true == f->mod_width)
		while (i < f->mod_width_value)
		{
			if (f->flag_zero && !(f->flag_minus))
				bytes_written += write(1, "0", 1);
			else
				bytes_written += write(1, " ", 1);
			i += 1;
		}
	if (false == f->flag_minus)
		bytes_written += write(1, &this_char, 1);
	return (bytes_written);
}
