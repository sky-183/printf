/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 15:59:38 by vflander          #+#    #+#             */
/*   Updated: 2020/05/04 15:59:38 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Outputs the integer ’n’ to the given file descriptor
*/

void	ft_putnbr_fd(int n, int fd)
{
	if (INT_MIN == n)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' - n % 10, fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}
