/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 15:54:40 by vflander          #+#    #+#             */
/*   Updated: 2020/05/04 15:54:40 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Outputs the string ’s’ to the given file descriptor, followed by a newline
*/

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			ft_putchar_fd(*(s++), fd);
		ft_putchar_fd('\n', fd);
	}
}
