/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 10:18:02 by vflander          #+#    #+#             */
/*   Updated: 2020/08/04 09:24:35 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
//for testing only
# include "libft/libft.h"
//# include <stdio.h>

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

#endif
