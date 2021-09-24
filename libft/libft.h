/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:10:48 by lbatista          #+#    #+#             */
/*   Updated: 2021/09/24 14:25:43 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

// Original libft functions

/**
 * @brief Checks if the passed character is a decimal digit character. Decimal
 * digits are (numbers) − 0 1 2 3 4 5 6 7 8 9.
 *
 * @param c This is the character to be checked.
 * @return This function returns non-zero value if c is a digit, else it
 * returns 0.
 */
int		ft_isdigit(int c);

/**
 * @brief Checks if the passed character is ASCII.
 *
 * @param c This is the character to be checked.
 * @return This function returns non-zero value if c is an ASCII, else it
 * returns 0.
 */
int		ft_isascii(int c);

/**
 * @brief Checks whether the passed character is printable. A printable
 * character is a character that is not a control character. Printable
 * characters are >= SPACE and <= ~.
 *
 * @param c This is the character to be checked.
 * @return This function returns a non-zero value(true) if c is a printable
 * character else, zero (false).
 */
int		ft_isprint(int c);

/**
 * @brief Computes the length of the string s up to, but not including the
 * terminating null character. Example: ft_strlen("1234") => 4
 *
 * @param s This is the string whose length is to be found.
 * @return This function returns the length of string.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Searches for the first occurrence of the character c
 * (an unsigned char) in the string pointed to by the argument s. The
 * terminating null	character is considered	part of	the string; therefore
 * if c is \\0, the functions locate the terminating \\0.
 *
 * @param s This is the C string to be scanned.
 * @param c This is the character to be located. It is passed as int,
 * but it is internally converted back to char.
 * @return This returns a pointer to the first occurrence of the character c
 * in the string s, or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Returns a pointer to a null-terminated byte string, which is a
 * duplicate of the string pointed to by str. The returned pointer must be
 * passed to free to avoid a memory leak. If an error occurs, a null pointer
 * is returned and errno may be set.
 *
 * @param s Pointer to the null-terminated byte string to duplicate.
 * @return A pointer to the newly allocated string, or a null pointer
 * if an error occurred.
 */
char	*ft_strdup(const char *s1);

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of ’s1’ and ’s2’.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Copies len bytes from memory area src to memory area dst.
 *If src and dst overlap, the results are not defined.
 * @param dst This is pointer to the destination array where the content is
 * to be copied, type-casted to a pointer of type void*.
 * @param src This is pointer to the source of data to be copied, type-casted
 * to a pointer of type void*.
 * @param len This is the number of bytes to be copied.
 * @return This function returns a pointer to destination, which is dst.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief Copies the character c (an unsigned char) to the first len characters
 * of the string pointed to, by the argument dest.
 *
 * @param dest This is a pointer to the block of memory to fill.
 * @param c This is the value to be set. The value is passed as an int, but
 * the function fills the block of memory using the unsigned char conversion
 * of this value.
 * @param len This is the number of bytes to be set to the value.
 * @return This function returns a pointer to the memory area dest.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Copies up to dstsize - 1 characters from the string src to dst,
 * NUL-terminating the result if dstsize is not 0.
 *
 * @param dst This is the pointer to the destination array where the content
 * is to be copied.
 * @param src This is the string to be copied.
 * @param dstsize Full size of the destination buffer.
 * @return The total length of the string they tried to create. That means the
 * length of src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief Appends string src to the end of dst. It will append at most dstsize
 * - strlen(dst) - 1 characters. It will then NUL-terminate, unless dstsize is
 * 0 or the original dst string was longer than dstsize. If the src and dst
 * strings overlap, the behavior is undefined.
 *
 * @param dst This is pointer to the destination array, which should contain
 * a C string, and should be large enough to contain the concatenated
 * resulting string.
 * @param src This is the string to be appended.
 * @param dstsize Full size of the destination buffer.
 * @return The total length of the string they tried to create. That means the
 * initial length of dst + the length of src.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

// New libft functions

/**
 * @brief Allocates (with malloc(3)) and returns a new string,
 *  which is the result of
 * the concatenation of ’s’ and the char ’c’.
 *
 * @param s The prefix string.
 * @param c The suffix char.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_appendchr(char const *s, char const c);

/**
 * @briefThe uitoa_base() converts an unsigned integer into a string,
 * passing it to the base given as an argument.
 *
 * @param nbr The unsigned long to convert.
 * @param base The base in which to convert the number to
 * @return The string representing the converted number.
 */
char	*ft_uitoa_base(unsigned long nbr, char *base);

/**
 * @brief The strdup() function allocates sufficient memory
 * for a copy of the strings1, up until a 'n' total bytesm,
 * does the copy, and returns a pointer to it.
 *
 * @param s1 The string to duplicate.
 * @param n The number of bytes to duplicate
 * @return The strdup() function returns the pointer to the copy of s1.
 */
char	*ft_strndup(const char *s1, size_t n);

#endif
