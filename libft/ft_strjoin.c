/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbatista <lbatista@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:20:25 by lbatista          #+#    #+#             */
/*   Updated: 2021/09/28 16:58:47 by lbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	size_t	size;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	size = ft_strlen(s1) + ft_strlen(s2) + 1;
// 	str = (char *)malloc(sizeof(char) * size);
// 	if (!str)
// 		return (NULL);
// 	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
// 	ft_strlcat(str, s2, size);
// 	return (str);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ccat;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = (ft_strlen((char *)s1));
	len_s2 = (ft_strlen((char *)s2));
	ccat = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (ccat == NULL)
		return (NULL);
	ft_strlcpy(&ccat[0], s1, len_s1 + 1);
	ft_strlcpy(&ccat[len_s1], s2, len_s2 + 1);
	return (ccat);
}
