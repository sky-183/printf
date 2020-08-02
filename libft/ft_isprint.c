/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:33:27 by vflander          #+#    #+#             */
/*   Updated: 2020/05/05 20:33:27 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Checks for any printable character including space.
*/

int		ft_isprint(int c)
{
	return (((unsigned char)c < 127) && ((unsigned char)c > 31));
}
