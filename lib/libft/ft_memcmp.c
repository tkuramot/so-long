/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:46:09 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 19:18:48 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;

	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	while (n > 0 && (*b1 == *b2))
	{
		b1++;
		b2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*b1 - *b2);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char s1[10] = "1234";
// 	char s2[10] = "1233";
// 	printf("%d\n", ft_memcmp(NULL, NULL, 0));
// 	// printf("%d\n", ft_memcmp(NULL, NULL, 1));
// 	printf("%d\n", ft_memcmp(s1, NULL, 0));
// 	// printf("%d\n", ft_memcmp(s1, NULL, 1));
// 	printf("%d\n", ft_memcmp(NULL, s2, 0));
// 	// printf("%d\n", ft_memcmp(NULL, s2, 1));

// 	printf("%d\n", memcmp(NULL, NULL, 0));
// 	// printf("%d\n", memcmp(NULL, NULL, 1));
// 	printf("%d\n", memcmp(s1, NULL, 0));
// 	// printf("%d\n", memcmp(s1, NULL, 1));
// 	printf("%d\n", memcmp(NULL, s2, 0));
// 	// printf("%d\n", memcmp(NULL, s2, 1));
// }
