/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print_type_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 13:17:42 by vflander          #+#    #+#             */
/*   Updated: 2020/08/04 13:18:06 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Prints string-type argument according to flags and specifiers.
**	Returns number of bytes written.
*/

int			printf_print_type_string(va_list *ap, t_format_data *f)
{
	int		bytes_written;
	int		len;
	int		i;
	char	*str;

	bytes_written = 0;
	str = va_arg(*ap, char*);
	if (NULL == str)
		str = "(null)";
	len = ft_strlen(str);
	if (f->mod_precision && (f->mod_precision_value < len))
		len = f->mod_precision_value;
	i = len;
	if (true == f->flag_minus)
		while (len--)
			bytes_written += write(1, str++, 1);
	if (true == f->mod_width)
		while (i++ < f->mod_width_value)
			bytes_written += write(1, " ", 1);
	if (false == f->flag_minus)
		while (len--)
			bytes_written += write(1, str++, 1);
	return (bytes_written);
}
