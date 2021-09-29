/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:00:52 by lbatista          #+#    #+#             */
/*   Updated: 2021/09/29 10:46:45 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>
# include <wchar.h>
# include "../libft/libft.h"

# define HOLDER_CONVERSION "cspdiuxX%o"
# define HOLDER_ALL "-0# +123456789*"
# define HOLDER_ALL_FLAGS "-0# +"
# define HOLDER_JUSTIFY '-'
# define HOLDER_PREFIX "# +"
# define HOLDER_PAD '0'
# define HOLDER_PRECISION '.'
# define HOLDER_STAR '*'

# define OCTAL_BASE "01234567"
# define DECIMAL_BASE "0123456789"
# define HEXADECIMAL_U_BASE "0123456789ABCDEF"
# define HEXADECIMAL_L_BASE "0123456789abcdef"

# define PTR_HEX_L_PREFIX "0x"
# define HEX_U_PREFIX "0X"
# define OCT_PREFIX "0"
# define MINUS '-'
# define PLUS '+'
# define SPACE ' '

typedef struct s_format
{
	const char	*format;
	va_list		ap;
	size_t		i;
	size_t		len;
}			t_format;

typedef struct s_holder
{
	int		left_justify;
	char	*prefix;
	char	padding;
	int		width;
	int		precision;
	char	conversion;
	char	*argument;
	size_t	len;
}			t_holder;

/*
*	LIBRARY
*	#include <stdio.h>
*	DESCRIPTION
*	The  functions in the printf() family produce output according to a format
*	as described below.  The functions printf() and vprintf() write output to
*	stdout, the standard output stream.
*	PARAMETERS
*	#1. The string format in which the output will be printed.
*	... The variadic arguments passed to the format string's placeholders. In
*	the vprintf() function, the variadic argument are already passed as a
*	va_list type.
*	RETURN VALUES
*	Upon successful return, these functions return the number of characters
*	printed (excluding the null byte used to end output to strings).
*/
int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list ap);

/**
 * @brief Initialize the format struct with the string given and
 * the va_list variable,
 * setting the initial values of len and the counter i to 0.
 *
 * @param format The string format in which the output will be printed.
 * @param ap The variadic arguments list
 * @return t_format* The new, inilialized variable struct format.
 */
t_format	*ft_initialize_format(const char *format, va_list ap);
/**
 * @brief Initialize the holder struct that will retain the information of the
 * placeholders flags and conversions. For the mandatory part, that means only
 * the conversion variable.
 *
 * @return t_holder* The new, inilialized variable struct holder.
 */
t_holder	*ft_initialize_holder(void);

/**
 * @brief The  placeholder() function manages whatever comes after
 * the '%' char in the  * printf()'s family functions.
 *  It calls the initialize() function for the
 * format struct,as well as the parse() function that will eventually
 * convert the argument passed to the va_list into the holder struct.
 *  At the end, itwill print to the screen the converted
 * string of the respective argument.
 *
 * @param fmt The t_format struct that holds information about
 * the string to be formatted.
 */
void		ft_placeholder(t_format *fmt);
/**
 * @brief The parse() function will take the format string
 * from the index in which the placeholder begins,
 * and will attempt to analyze and organize its flags and
 * conversors into a struct of type t_holder,
 * using other parsing subfunctions.
 *
 * @param fmt The t_format struct that holds information about
 * the string to be formatted.
 * @param h The t_holder struct that holds all the information about
 * the placeholder and its flags.
 * @return void* it returns the t_holder variable that holds all
 * the information about that particular placeholder.
 */
void		*ft_parse(t_format *fmt, t_holder *h);
void		ft_parse_flags(t_format *fmt, t_holder *h);
void		ft_parse_width(t_format *fmt, t_holder *h);
void		ft_parse_precision(t_format *fmt, t_holder *h);
void		ft_parse_conversion(t_format *fmt, t_holder *h);

/**
 * @brief  Much like a switch case operator,
 * the type_conversion() function takes the
 * format and holder structs that, in that moment, already hold all the
 * information necessary to perform the placeholder's intended conversion,
 * and orients each one to its specific conversion functions.
 *
 * @param fmt The t_format struct that holds information about
 * the string to be formatted.
 * @param h The t_holder struct that holds all the information about
 * the placeholder and its flags.
 */
void		ft_type_conversion(t_format *fmt, t_holder *h);
/**
 * @brief Converts the variadic argument into a single character string,
 * returning it into the holder's 'argument' variable.
 *
 * @param fmt The t_format struct that holds information about
 * the string to be formatted.
 * @param h The t_holder struct that holds all the information about
 * the placeholder and its flags.
 */
void		ft_convert_c(t_format *fmt, t_holder *h);
/**
 * @brief Converts the variadic argument into a full string,
 * returning it into the holder's 'argument' variable.
 *
 * @param fmt The t_format struct that holds information about
 * the string to be formatted.
 * @param h The t_holder struct that holds all the information about
 * the placeholder and its flags.
 */
void		ft_convert_s(t_format *fmt, t_holder *h);

/**
 * @brief Converts the variadic argument into a string representing its pointer
 * location in hexadecimal value, returning it into the holder's 'argument'
 * variable.
 *
 * @param fmt The t_format struct that holds information about
 * the string to be formatted.
 * @param h The t_holder struct that holds all the information about
 * the placeholder and its flags.
 */
void		ft_convert_p(t_format *fmt, t_holder *h);
/**
 * @brief Converts the variadic argument into a decimal number string
 * returning it into the holder's 'argument' variable.
 *
 * @param fmt The t_format struct that holds information about
 * the string to be formatted.
 * @param h The t_holder struct that holds all the information about
 * the placeholder and its flags.
 */
void		ft_convert_d_i(t_format *fmt, t_holder *h);
/**
 * @brief Converts the variadic argument into a numerical string of any base,
 * returning it into the holder's 'argument' variable.
 *
 * @param fmtThe t_format struct that holds information about
 * the string to be formatted.
 * @param h The t_holder struct that holds all the information about
 * the placeholder and its flags.
 * @param base
 */
void		ft_convert_ux(t_format *fmt, t_holder *h, char *base);
/**
 * @brief Converts the '%' into a single character of its kind.
 *
 * @param h The t_holder struct that holds all the information about
 * the placeholder and its flags.
 */
void		ft_convert_pct(t_holder *h);

// Conversions utils
void		ft_fill_left_pad(char **src, char padding, int width);
void		ft_fill_right_pad(char **src, char padding, int width);
void		ft_add_prefix(t_holder	*h, int sign);

#endif
