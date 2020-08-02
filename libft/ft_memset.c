/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:22:20 by vflander          #+#    #+#             */
/*   Updated: 2020/05/05 22:22:20 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Fills the first 'n' bytes of the memory area pointed to by 's' with
**	the constant byte 'c'. Returns a pointer to 's'.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char*)s + i) = (unsigned char)c;
		i += 1;
	}
	return (s);
}
