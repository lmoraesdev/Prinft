/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:17:49 by lbatista          #+#    #+#             */
/*   Updated: 2021/09/28 16:45:38 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"
static void	ft_convert_d_i_width(t_holder *h, int sign);

void	ft_convert_d_i(t_format *fmt, t_holder *h)
{
	int			sign;
	long int	arg;

	sign = 1;
	arg = (int)va_arg(fmt->ap, int);
	if (arg < 0)
		sign *= -1;
	h->argument = ft_uitoa_base(sign * arg, DECIMAL_BASE);
	if (h->precision > -1)
	{
		if (!h->precision && arg == 0)
		{
			free(h->argument);
			h->argument = ft_strdup("");
		}
		ft_fill_left_pad(&h->argument, '0', h->precision);
		h->padding = ' ';
	}
	ft_convert_d_i_width(h, sign);
	h->len = ft_strlen(h->argument);
}

static void	ft_convert_d_i_width(t_holder *h, int sign)
{
	if (h->left_justify)
	{
		ft_add_prefix(h, sign);
		ft_fill_right_pad(&h->argument, ' ', h->width);
	}
	else
	{
		if (h->padding == ' ')
		{
			ft_add_prefix(h, sign);
			ft_fill_left_pad(&h->argument, h->padding, h->width);
		}
		else if (h->padding == '0')
		{
			if (sign < 0 || ft_strchr(h->prefix, ' ') || \
				ft_strchr(h->prefix, '+'))
				ft_fill_left_pad(&h->argument, h->padding, h->width - 1);
			else
				ft_fill_left_pad(&h->argument, h->padding, h->width);
			ft_add_prefix(h, sign);
		}
	}
}
