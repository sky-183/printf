/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:47:15 by vflander          #+#    #+#             */
/*   Updated: 2020/05/05 20:47:15 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Returns upper case letter for letters 'a' - 'z' and same letter otherwise.
*/

int		ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c - 32);
	return (c);
}
