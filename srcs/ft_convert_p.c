/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:03:46 by lbatista          #+#    #+#             */
/*   Updated: 2021/09/27 19:14:28 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static char	*ft_nullset(t_holder *h)
{
	char	*number;

	if (h->precision > -1)
	{
		number = (char *)malloc((h->precision + 1) * sizeof(char));
		if (!number)
			return (NULL);
		ft_memset(number, '0',(size_t)h->precision);
		number[h->precision] = '\0';
	}
	else
		number = ft_strdup("0");
	return (number);
}

void	ft_convert_p(t_format *fmt, t_holder *h)
{
	void	*ptr;
	char	*number;

	number = NULL;
	ptr = va_arg(fmt->ap, void *);
	if (!ptr)
		number = ft_nullset(h);
	else
		number = ft_uitoa_base((unsigned long)ptr, HEXADECIMAL_L_BASE);
	h->argument = ft_strjoin(PTR_HEX_L_PREFIX, number);
	free(number);
	if (!h->left_justify)
		ft_fill_left_pad(&h->argument, ' ', h->width);
	else
		ft_fill_right_pad(&h->argument, ' ', h->width);
	h->len = ft_strlen(h->argument);
}
