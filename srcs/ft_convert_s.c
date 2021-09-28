/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:18:26 by lbatista          #+#    #+#             */
/*   Updated: 2021/09/28 16:47:23 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_convert_s(t_format *fmt, t_holder *h)
{
	char	*s;
	int		len;
	char	*temp;

	s = ft_strdup(va_arg(fmt->ap, char *));
	if (!s)
		s = ft_strdup("(null)");
	len = (int)ft_strlen(s);
	h->argument = (char *)malloc((len + 1) * sizeof(char));
	if (!h->argument)
		return ;
	ft_strlcpy(h->argument, s, len + 1);
	if (h->precision > -1)
	{
		temp = h->argument;
		h->argument = ft_strndup(temp, (size_t)h->precision);
		free(temp);
	}
	if (!h->left_justify)
		ft_fill_left_pad(&h->argument, ' ', h->width);
	else
		ft_fill_right_pad(&h->argument, ' ', h->width);
	h->len = ft_strlen(h->argument);
	free(s);
}
