/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:53:18 by vflander          #+#    #+#             */
/*   Updated: 2020/05/05 20:53:18 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Returns lower case letter for letters 'A' - 'Z' and same letter otherwise.
*/

int		ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (c + 32);
	return (c);
}
