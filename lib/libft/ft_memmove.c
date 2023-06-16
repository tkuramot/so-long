/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:01:45 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 19:19:45 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (dst <= src)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		d += len;
		s += len;
		while (len-- > 0)
		{
			*--d = *--s;
		}
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char dst[10] = "1234";
// 	char src[10];
// 	printf("%p\n", ft_memmove(NULL, NULL, 0));
// 	printf("%p\n", ft_memmove(NULL, NULL, 1));
// 	printf("%p\n", ft_memmove(dst, NULL, 0));
// 	// printf("%p\n", ft_memmove(dst, NULL, 1));
// 	printf("%p\n", ft_memmove(NULL, src, 0));
// 	// printf("%p\n", ft_memmove(NULL, src, 1));

// 	printf("%p\n", memmove(NULL, NULL, 0));
// 	printf("%p\n", memmove(NULL, NULL, 1));
// 	printf("%p\n", memmove(dst, NULL, 0));
// 	// printf("%p\n", memmove(dst, NULL, 1));
// 	printf("%p\n", memmove(NULL, src, 0));
// 	//  printf("%p\n", memmove(NULL, src, 1));
// }
