/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:57:55 by lbatista          #+#    #+#             */
/*   Updated: 2021/09/28 17:00:27 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	unsigned char		*ptr;
// 	unsigned char		*ptr2;

// 	ptr = (unsigned char *)dest;
// 	ptr2 = (unsigned char *)src;
// 	if ((!src && !dest) || !n)
// 		return (dest);
// 	while (n--)
// 		*ptr++ = *ptr2++;
// 	return (dest);
// }

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dstc;
	unsigned char	*srcc;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dstc = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	while (i < n)
	{
		dstc[i] = srcc[i];
		i++;
	}
	return (dst);
}
