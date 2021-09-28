/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:43:12 by lbatista          #+#    #+#             */
/*   Updated: 2021/09/28 16:44:21 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

t_format	*ft_initialize_format(const char *format, va_list ap)
{
	t_format	*fmt;

	fmt = malloc(sizeof(t_format));
	if (!fmt)
		return (NULL);
	fmt->format = format;
	va_copy(fmt->ap, ap);
	fmt->i = 0;
	fmt->len = 0;
	return (fmt);
}

t_holder	*ft_initialize_holder(void)
{
	t_holder	*h;

	h = malloc(sizeof(t_holder));
	if (!h)
		return (NULL);
	h->left_justify = 0;
	h->prefix = ft_strdup("");
	h->padding = ' ';
	h->width = 0;
	h->precision = -1;
	h->conversion = '\0';
	h->argument = NULL;
	h->len = 0;
	return (h);
}
