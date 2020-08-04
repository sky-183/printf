/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 13:27:59 by vflander          #+#    #+#             */
/*   Updated: 2020/08/04 13:34:52 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Iterates on the format string (until first non-flag character) and saves
**	all found flags to given data structure (t_format_data).
*/

void		printf_parse_flags(const char **format_string, t_format_data *f)
{
	while (**format_string)
	{
		if (**format_string == '-')
			f->flag_minus = true;
		else if (**format_string == '+')
			f->flag_plus = true;
		else if (**format_string == ' ')
			f->flag_space = true;
		else if (**format_string == '#')
			f->flag_hash = true;
		else if (**format_string == '0')
			f->flag_zero = true;
		else
			break ;
		(*format_string)++;
	}
}

/*
**	Iterates on the format string (right after 'printf_parse_flag' function)
**	and saves width modifiers to given data structure (t_format_data).
**	Return (0) if OK or (-1) on invalid width (INT_MIN via *).
*/

int			printf_parse_mod_width(va_list *ap, const char **format_string,\
			t_format_data *f)
{
	if ('*' == **format_string)
	{
		f->mod_width_value = va_arg(*ap, int);
		*format_string += 1;
		if (f->mod_width_value < 0)
		{
			if (INT_MIN == f->mod_width_value)
				return (-1);
			f->flag_minus = true;
			f->mod_width_value *= -1;
		}
		f->mod_width = true;
	}
	else
	{
		f->mod_width_value = ft_atoi(*format_string);
		while (ft_isdigit(**format_string))
		{
			f->mod_width = true;
			*format_string += 1;
		}
	}
	return (0);
}

/*
**	Iterates on the format string (right after 'printf_parse_width' function)
**	and saves precision modifiers to given data structure (t_format_data).
*/

int			printf_parse_mod_precision(va_list *ap, const char **format_string,\
			t_format_data *f)
{
	*format_string += 1;
	if ('*' == **format_string)
	{
		f->mod_precision_value = va_arg(*ap, int);
		*format_string += 1;
	}
	else if (ft_isdigit(**format_string))
	{
		f->mod_precision_value = ft_atoi(*format_string);
		while (ft_isdigit(**format_string))
			*format_string += 1;
	}
	if (f->mod_precision_value >= 0)
		f->mod_precision = true;
	if (f->mod_precision)
		f->flag_zero = 0;
	return (0);
}

/*
**	Saves given character as a mod type.
**	Return (0) for known types and (-1) for unknown.
*/

int			printf_parse_mod_type(const char **format_string, t_format_data *f)
{
	char	c;

	c = **format_string;
	f->mod_type = c;
	*format_string += 1;
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' \
		|| c == 'x' || c == 'X' || c == '%')
		f->format_is_valid = true;
	if (false == f->format_is_valid)
		return (-1);
	return (0);
}
