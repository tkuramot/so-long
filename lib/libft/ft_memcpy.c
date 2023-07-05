/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:42:19 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/20 18:42:33 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char dst[10] = "1234";
// 	char src[10];
// 	printf("%p\n", ft_memcpy(NULL, NULL, 0));
// 	printf("%p\n", ft_memcpy(NULL, NULL, 1));
// 	printf("%p\n", ft_memcpy(dst, NULL, 0));
// 	// printf("%p\n", ft_memcpy(dst, NULL, 1));
// 	printf("%p\n", ft_memcpy(NULL, src, 0));
// 	// printf("%p\n", ft_memcpy(NULL, src, 1));

// 	printf("%p\n", memcpy(NULL, NULL, 0));
// 	printf("%p\n", memcpy(NULL, NULL, 1));
// 	printf("%p\n", memcpy(dst, NULL, 0));
// 	// printf("%p\n", memcpy(dst, NULL, 1));
// 	printf("%p\n", memcpy(NULL, src, 0));
// 	//  printf("%p\n", memcpy(NULL, src, 1));
// }
