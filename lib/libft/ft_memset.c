/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:06:40 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/20 18:42:49 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	s = (unsigned char *)b;
	while (len-- > 0)
	{
		*s++ = (unsigned char)c;
	}
	return (b);
}

// #include <string.h>

// int	main(void)
// {
// 	// ft_memset(NULL, 0, 2);
// 	ft_memset(NULL, 0, 0);

// 	// memset(NULL, 0, 2);
// 	memset(NULL, 0, 0);
// }
