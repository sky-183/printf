/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 10:18:02 by vflander          #+#    #+#             */
/*   Updated: 2020/08/04 13:37:33 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct	s_format
{
	bool		flag_minus;
	bool		flag_plus;
	bool		flag_space;
	bool		flag_hash;
	bool		flag_zero;
	bool		mod_width;
	int			mod_width_value;
	bool		mod_precision;
	int			mod_precision_value;
	char		mod_type;
	bool		format_is_valid;
	int			misc_base_len;
	int			misc_num_of_zeros;
}				t_format_data;

int				ft_printf(const char *format_string, ...);
void			printf_parse_flags(const char **format_string,\
				t_format_data *f);
int				printf_parse_mod_width(va_list *ap,\
				const char **format_string, t_format_data *f);
int				printf_parse_mod_precision(va_list *ap,\
				const char **format_string, t_format_data *f);
int				printf_parse_mod_type(const char **format_string,\
				t_format_data *f);
int				printf_print_type_char(va_list *ap, t_format_data *f);
int				printf_print_type_string(va_list *ap, t_format_data *f);
int				printf_print_type_int(va_list *ap, t_format_data *f);
int				printf_print_type_hex(va_list *ap, t_format_data *f);

#endif
