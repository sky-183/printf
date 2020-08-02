/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:30:11 by vflander          #+#    #+#             */
/*   Updated: 2020/05/05 20:30:11 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Checks whether c is a 7-bit unsigned char value that fits into the
**	ASCII character set
*/

int		ft_isascii(int c)
{
	return ((unsigned char)c < 128);
}
