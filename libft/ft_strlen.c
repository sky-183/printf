/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:19:09 by vflander          #+#    #+#             */
/*   Updated: 2020/05/04 18:19:09 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Computes the length of the string 's' up to, but not including
**	the terminating null character.
*/

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*(s + len))
		len += 1;
	return (len);
}
