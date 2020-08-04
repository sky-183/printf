/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 10:15:59 by vflander          #+#    #+#             */
/*   Updated: 2020/08/04 09:47:05 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//FIXME:
#include <stdio.h>

/*
**	Takes structure (t_format_data) and fills everything with zeros.
*/

void			printf_init_struct(t_format_data *this_struct_ptr)
{
	this_struct_ptr->flag_minus = false;
	this_struct_ptr->flag_plus = false;
	this_struct_ptr->flag_space = false;
	this_struct_ptr->flag_hash = false;
	this_struct_ptr->flag_zero = false;
	this_struct_ptr->mod_width = false;
	this_struct_ptr->mod_precision = false;
	this_struct_ptr->format_is_valid = false;
	this_struct_ptr->mod_width_value = 0;
	this_struct_ptr->mod_precision_value = 0;
	this_struct_ptr->mod_type = '\0';
	this_struct_ptr->misc_base_len = 0;
	this_struct_ptr->misc_num_of_zeros = 0;
}

/*
**	Debug function.
**	Prints the entire structure of 't_format_data' type.
*/

/*
void					print_struct(t_format_data *this_struct_ptr)
{
	printf("\nflag minus: %d", this_struct_ptr->flag_minus);
	printf("\nflag plus: %d", this_struct_ptr->flag_plus);
	printf("\nflag space: %d", this_struct_ptr->flag_space);
	printf("\nflag hash: %d", this_struct_ptr->flag_hash);
	printf("\nflag zero: %d", this_struct_ptr->flag_zero);
	printf("\nmod width: %d", this_struct_ptr->mod_width);
	printf("\nmod width value: %d", this_struct_ptr->mod_width_value);
	printf("\nmod precision: %d", this_struct_ptr->mod_precision);
	printf("\nmod precision value: %d", this_struct_ptr->mod_precision_value);
	printf("\nmod type: %c", this_struct_ptr->mod_type);
	printf("\nvalid: %d", this_struct_ptr->format_is_valid);
}
*/
/*
**	Iterates on the format string (until first non-flag character) and saves
**	all found flags to given data structure (t_format_data).
*/

void			printf_parse_flags(const char **format_string,\
				t_format_data *f)
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
			break;
		(*format_string)++;
	}
}

/*
**	Iterates on the format string (right after 'printf_parse_flag' function)
**	and saves all found modifiers (width, precision and type) to given data
**	structure (t_format_data).
*/

int			printf_parse_modifiers_width(va_list *ap,\
			const char **format_string, t_format_data *f)
{
	//Width
	if ('*' == **format_string)
	{
		//Parse from 'ap' as int and eval negatives separately
		f->mod_width_value = va_arg(*ap, int);
		*format_string += 1;
		//deal with negatives
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
		//Parse with atoi (from string to int)
		f->mod_width_value = ft_atoi(*format_string);
		while (ft_isdigit(**format_string))
		{
			f->mod_width = true;
			*format_string += 1;
		}
	}
	//End width
	return (0);
}

int			printf_parse_modifiers_precision(va_list *ap,\
			const char **format_string, t_format_data *f)
{
	*format_string += 1;// skipping initial '.'
	if ('*' == **format_string)
	{
		f->mod_precision_value = va_arg(*ap, int);
		*format_string += 1;
	}
	//allowing only digits. should add '-' and '+'? negative is not allowed, tho
	else if (ft_isdigit(**format_string))
	{
		f->mod_precision_value = ft_atoi(*format_string);
		while (ft_isdigit(**format_string))
			*format_string += 1;
	}
	if (f->mod_precision_value >= 0)
		f->mod_precision = true;//negative precision is omitted
	//When precision is present, '0' flag is omitted
	//TODO: Do I need to specify types here as well?
	if (f->mod_precision)
		f->flag_zero = 0;
	return (0);
}

int			printf_parse_modifier_type(const char **format_string,\
			t_format_data *f)
{
	char	c;

	c = **format_string;
	f->mod_type = c;
	*format_string += 1;//skipping format symbol
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' \
		|| c == 'x' || c == 'X' || c == '%')
		f->format_is_valid = true;
	if (false == f->format_is_valid)
		return (-1);
	return (0);
}

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
	i = 1;//our acutal character already included
	if ('%' == f->mod_type)
		this_char = f->mod_type;
	else
		this_char = (unsigned char)va_arg(*ap, int);
	if (true == f->flag_minus)
		bytes_written += write(1, &this_char, 1);
	if (true == f->mod_width)
		while (i < f->mod_width_value)
		{
			if (f->flag_zero)
				bytes_written += write(1, "0", 1);
			else
				bytes_written += write(1, " ", 1);
			i += 1;
		}
	if (false == f->flag_minus)
		bytes_written += write(1, &this_char, 1);
	return (bytes_written);
}

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

/*
**	Returns length of number, including '-' for negatives and ' ' or '+' for
**	positives (if those flags are specified) and additional zeros for precision
**	or '0' flag.
*/

int				printf_get_number_len(long int number, t_format_data *f)
{
	int			len;
	long int	tmp;

	len = 1;
	//for nonprintable zero
	if ((0 == number) && (true == f->mod_precision) && \
		(0 == f->mod_precision_value))
		len = 0;
	tmp = number;
	while (tmp / 10)
		{
			tmp /= 10;
			len += 1;
		}
	//counting number of zeros (precision) before counting sign/space
	if (true == f->mod_precision && \
		f->mod_precision_value > len)
	{
		f->misc_num_of_zeros = f->mod_precision_value - len;
		len += f->misc_num_of_zeros;
	}
	if (number < 0)
		len += 1;
	else if (f->mod_type != 'u')
		if (f->flag_plus || f->flag_space)
			len += 1;
	//counting number of zeros ('0' flag)
	if (true == f->mod_width)
		if (true == f->flag_zero && !(f->flag_minus))
		{
			f->misc_num_of_zeros = f->mod_width_value - len;
			if (f->misc_num_of_zeros < 0)
				f->misc_num_of_zeros = 0;
			len += f->misc_num_of_zeros;
		}
	//FIXME: debug
	//printf("((get_len:%d))", len);
	return (len);
}

/*
**	Prints given long int to the stdout.
**	Returns number of bytes written.
*/

int		printf_putnbr_long(long int n)
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

int			printf_print_type_int_number(long int number,\
			t_format_data *f)
{
	int		bytes_written;
	//FIXME:
	int		debug;

	bytes_written = 0;
	//print ' ' or '+' if needed
	if (number >= 0 && (f->mod_type != 'u'))
	{
		if (f->flag_plus)
			bytes_written += write(1, "+", 1);
		else if (f->flag_space)
			bytes_written += write(1, " ", 1);
	}
	//print '-'
	if (number < 0)
	{
		bytes_written += write(1, "-", 1);
		number = -number;
	}
	//print leading '0' for precision
	while (f->misc_num_of_zeros > 0)
	{
		bytes_written += write(1, "0", 1);
		f->misc_num_of_zeros -= 1;
	}
	//printing actual number;
	//if this is non-printable zero
	if ((0 == number) && (true == f->mod_precision) && \
		(0 == f->mod_precision_value))
		bytes_written += 0;//print nothing for this combination
	else//if this is printable anything else
	{
		//FIXME: debug
		debug = printf_putnbr_long(number);
		// printf("((putnbr:%d))", debug);
		bytes_written += debug;
	}
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
	int			num_of_spaces;

	if ('u' == f->mod_type)
		number = va_arg(*ap, unsigned int);
	else
		number = va_arg(*ap, int);
	if (f->mod_width)
		num_of_spaces = f->mod_width_value - printf_get_number_len(number, f);
	if (num_of_spaces < 0)
		num_of_spaces = 0;
	//TODO: debug:
	//printf("((spaces:%d))", num_of_spaces);
	bytes_written = 0;// 0 if doing it iside in the function
	/*
	if (number < 0 && f->mod_precision &&\
		(f->mod_precision_value > 1))
		bytes_written += 1;//counting '-' sign
	*/
	//print number
	if (true == f->flag_minus)
		bytes_written += printf_print_type_int_number(number, f);
	//print fillers
	if (true == f->mod_width)
		while (num_of_spaces)
		{
			bytes_written += write(1, " ", 1);
			num_of_spaces -= 1;
		}
	//print number
	if (false == f->flag_minus)
		bytes_written += printf_print_type_int_number(number, f);
	return (bytes_written);
}

/*
**	Returns length of unsigned int in its hexadecimal representation.
*/

int			printf_get_number_len_hex(long int number)
{
	int		len;

	len = 1;
	while (number / 16)
		{
			number /= 16;
			len += 1;
		}
	return (len);
}

/*
**	Prints given unsigned int to stdout in hexadecimal form.
*/

void			printf_putnbr_long_hex(size_t n, bool capital)
{
	char		*digits;
	char		c;

	digits = "0123456789abcdef0123456789ABCDEF";

	if (n >= 16)
		printf_putnbr_long_hex(n / 16, capital);
	c = digits[(n % 16) + 16 * capital];
	write(1, &c, 1);
}

/*
**	Prints hexadecimal representation of unsigned int number with '0x' if
**	needed (but not spaces for width modifier).
**	Returns number of bytes written.
*/

int				printf_print_type_hex_number(size_t number,\
				t_format_data *f)
{
	int			bytes_written;
	char		mod_type;
	bool		capital;

	mod_type = f->mod_type;
	bytes_written = 0;
	if (true == f->flag_hash && (0 != number) && ('p' != mod_type))
	{
		write(1, "0", 1);
		write(1, &mod_type, 1);
	}
	if ('p' == mod_type)
		write(1, "0x", 2);
	if ('X' == mod_type)
		capital = true;
	else
		capital = false;
	printf_putnbr_long_hex(number, capital);

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
	int			len;

	if ('p' == f->mod_type)
		number = va_arg(*ap, size_t);
	else
		number = va_arg(*ap, unsigned int);
	len = printf_get_number_len_hex(number);
	if (true == f->flag_hash && (number != 0) &&\
		'p' != f->mod_type)
		len += 2;//'0x' when '#' flag present for non-zero values
	if ('p' == f->mod_type)
		len += 2;//always '0x' for 'p' type
	//TODO: debug:
	//printf("((%d))", len);
	bytes_written = len;
	//print number
	if (true == f->flag_minus)
		bytes_written += printf_print_type_hex_number(number, f);

	//print fillers
	if (true == f->mod_width)
		while (len < f->mod_width_value)
		{
			bytes_written += write(1, " ", 1);
			len += 1;
		}
	//print number
	if (false == f->flag_minus)
		bytes_written += printf_print_type_hex_number(number, f);

	return (bytes_written);
}

/*
**	Takes parsed specifator data (if it was correct) and arg list.
**	Prints given argument from arg list with corresponding function.
**	Returns number of bytes written.
*/
//TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:TODO:

int			printf_print_processed_struct(va_list *ap,\
			t_format_data *f)
{
	if ('c' == f->mod_type ||\
		'%' == f->mod_type)
		return printf_print_type_char(ap, f);
	if ('s' == f->mod_type)
		return printf_print_type_string(ap, f);
	if ('d' == f->mod_type ||\
		'i' == f->mod_type ||\
		'u' == f->mod_type)
		return printf_print_type_int(ap, f);
	if ('x' == f->mod_type ||\
		'X' == f->mod_type ||\
		'p' == f->mod_type)
		return printf_print_type_hex(ap, f);
	//will never get here anyway
	return (0);
}

/*
**	Prints fragment of printf's formatted string for one specificator.
**	It just 'magically' transform stuff like %-123.*d to end-result.
**	Parses and prints the string and returns number of bytes written
**	(or -1 on error).
**	'format_string' - pointer to '%' symbol in printf's format string.
*/


int						printf_print_formatted_block(va_list *ap,\
						const char **format_string, t_format_data *f)
{
	int					bytes_written;

	bytes_written = 0;
	printf_init_struct(f);

	//TODO:
	// test original printf with negative width and precision
	// (both as args and with *). And with some atoi-friendly symbols in str \t

	//Parse
	printf_parse_flags(format_string, f);
	if (-1 == printf_parse_modifiers_width(ap, format_string, f))
		return (-1);//on MIN_INT as * width modifier
	if ('.' == **format_string)
		if (-1 == printf_parse_modifiers_precision(ap, format_string,\
													f))
			return (-1);//on MIN_INT as * precision modifier
	if (-1 == printf_parse_modifier_type(format_string, f))
		return (-1);//on unknown format type symbol

	//Main part - print stuff
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

int						ft_printf(const char *format_string, ...)
{
	int					total_len_written;
	int					return_value;
	va_list				ap;
	t_format_data		f;


	if (NULL == format_string)
		return (-1);
	total_len_written = 0;
	va_start(ap, format_string);
	//print elements one by one, incrementing count
	while (*format_string)
	{
		if (*format_string == '%')
		{
			format_string += 1;
			// print evaluated expression if return != -1 (error)
			//returns number of symbols writted or -1 on error
			//use va_arg inside to grab next element
			return_value = printf_print_formatted_block(&ap, &format_string,\
												&f);
			if (-1 == return_value)
				return (-1);
			total_len_written += return_value;
		}
		else
		{
			write(1, format_string, 1);
			format_string += 1;
			total_len_written += 1;
		}
	}

	va_end(ap);
	return (total_len_written);
}

