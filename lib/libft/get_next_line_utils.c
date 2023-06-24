/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:46:36 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/24 14:08:31 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	find_chr(char *s, char c)
{
	size_t	idx;

	idx = 0;
	while (*s && *s++ != c)
		idx++;
	return (idx);
}

// Nullproof
size_t	ft_strlen_s(const char *s)
{
	size_t	len;

	len = 0;
	while (s && *s++)
		len++;
	return (len);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t n1, size_t n2)
{
	size_t	dstsize;
	char	*ret;
	char	*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dstsize = n1 + n2 + 1;
	ret = (char *)malloc(sizeof(char) * dstsize);
	if (ret == NULL)
		return (NULL);
	tmp = ret;
	while (n1--)
		*tmp++ = *s1++;
	while (n2--)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (ret);
}
