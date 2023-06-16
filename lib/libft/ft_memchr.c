/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:43:24 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/20 18:42:14 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*b;

	b = (unsigned char *)s;
	while (n > 0)
	{
		if (*b == (unsigned char)c)
			return (b);
		b++;
		n--;
	}
	return (NULL);
}

// #include <string.h>

// int	main(void)
// {
// 	// ft_memchr(NULL, 'a', 0);
// 	ft_memchr(NULL, 'a', 1);

// 	// memchr(NULL, 'a', 0);
// 	// memchr(NULL, 'a', 1);
// }
