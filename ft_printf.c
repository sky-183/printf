/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 10:15:59 by vflander          #+#    #+#             */
/*   Updated: 2020/08/04 13:39:20 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Takes structure (t_format_data) and fills everything with zeros.
*/

void				printf_init_struct(t_format_data *f)
{
	f->flag_minus = false;
	f->flag_plus = false;
	f->flag_space = false;
	f->flag_hash = false;
	f->flag_zero = false;
	f->mod_width = false;
	f->mod_precision = false;
	f->format_is_valid = false;
	f->mod_width_value = 0;
	f->mod_precision_value = 0;
	f->mod_type = '\0';
	f->misc_base_len = 0;
	f->misc_num_of_zeros = 0;
}

/*
**	Takes parsed specifator data (if it was correct) and arg list.
**	Prints given argument from arg list with corresponding function.
**	Returns number of bytes written.
*/

int					printf_print_processed_struct(va_list *ap, t_format_data *f)
{
	if ('c' == f->mod_type ||\
		'%' == f->mod_type)
		return (printf_print_type_char(ap, f));
	if ('s' == f->mod_type)
		return (printf_print_type_string(ap, f));
	if ('d' == f->mod_type ||\
		'i' == f->mod_type ||\
		'u' == f->mod_type)
		return (printf_print_type_int(ap, f));
	if ('x' == f->mod_type ||\
		'X' == f->mod_type ||\
		'p' == f->mod_type)
		return (printf_print_type_hex(ap, f));
	return (0);
}

/*
**	Prints fragment of printf's formatted string for one specificator.
**	It just 'magically' transform stuff like %-123.*d to end-result.
**	Parses and prints the string and returns number of bytes written
**	(or -1 on error).
**	'format_string' - pointer to '%' symbol in printf's format string.
*/

int					printf_print_formatted_block(va_list *ap,\
					const char **format_string, t_format_data *f)
{
	int				bytes_written;

	bytes_written = 0;
	printf_init_struct(f);
	printf_parse_flags(format_string, f);
	if (-1 == printf_parse_modifiers_width(ap, format_string, f))
		return (-1);
	if ('.' == **format_string)
		if (-1 == printf_parse_modifiers_precision(ap, format_string, f))
			return (-1);
	if (-1 == printf_parse_modifier_type(format_string, f))
		return (-1);
	bytes_written += printf_print_processed_struct(ap, f);
	return (bytes_written);
}

/*
**	Writes output to standard output stream (stdout) according to a format.
**	Returns the total number of bytes printed or '-1'  error.
**	Identical to standard libc function 'printf'.
**	https://en.wikipedia.org/wiki/Printf_format_string
**	https://ru.wikipedia.org/wiki/Printf
*/

int					ft_printf(const char *format_string, ...)
{
	int				bytes_written;
	int				ret_value;
	va_list			ap;
	t_format_data	f;

	if (NULL == format_string)
		return (-1);
	bytes_written = 0;
	va_start(ap, format_string);
	while (*format_string)
	{
		if (*format_string == '%')
		{
			format_string += 1;
			ret_value = printf_print_formatted_block(&ap, &format_string, &f);
			if (-1 == ret_value)
				return (-1);
			bytes_written += ret_value;
		}
		else
			bytes_written += write(1, format_string++, 1);
	}
	va_end(ap);
	return (bytes_written);
}
