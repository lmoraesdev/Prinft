/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:09:02 by lbatista          #+#    #+#             */
/*   Updated: 2021/09/27 13:16:27 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_convert_c(t_format *fmt, t_holder *h)
{
	char	ch;

	ch = (wint_t)va_arg(fmt->ap, wint_t);
	if (!h->width)
		h->width += 1;
	h->argument = (char *)malloc(h->width * sizeof(char));
	if (!h->argument)
		return ;
	ft_memset(h->argument, SPACE, h->width);
	if (!h-> left_justify == 1)
		h->argument[0] = ch;
	else
		h->argument[h->width - 1] = ch;
	h->len = h->width;
}
