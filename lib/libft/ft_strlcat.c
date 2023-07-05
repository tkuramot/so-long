/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:53:36 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/20 18:44:17 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t max_len)
{
	size_t	len;

	len = 0;
	while (max_len > 0 && *s++ != '\0')
	{
		len++;
		max_len--;
	}
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strnlen(dst, dstsize);
	if (dst_len == dstsize)
		return (src_len + dstsize);
	if (src_len < dstsize - dst_len)
		ft_memcpy(dst + dst_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dst_len, src, dstsize - dst_len - 1);
		dst[dst_len - dst_len - 1] = '\0';
	}
	return (dst_len + src_len);
}

// #include <string.h>

// int	main(void)
// {
// 	char dst[10] = "123";
// 	char src[10] = "45";
// 	// ft_strlcat(NULL, NULL, 0);
// 	// ft_strlcat(NULL, NULL, 1);
// 	// ft_strlcat(dst, NULL, sizeof dst);
// 	// ft_strlcat(dst, NULL, 0);
// 	// ft_strlcat(NULL, src, sizeof dst);
// 	ft_strlcat(NULL, src, 0);

// 	// strlcat(NULL, NULL, 0);
// 	// strlcat(NULL, NULL, 1);
// 	// strlcat(dst, NULL, sizeof dst);
// 	// strlcat(dst, NULL, 0);
// 	// strlcat(NULL, src, sizeof dst);
// 	strlcat(NULL, src, 0);
// }
