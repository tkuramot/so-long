/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:27:52 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/20 18:44:25 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	while (index + 1 < dstsize && *src != '\0')
	{
		*dst++ = *src++;
		index++;
	}
	if (dstsize > 0)
		*dst = '\0';
	while (*src++ != '\0')
		index++;
	return (index);
}

// #include <string.h>

// int	main(void)
// {
// 	char dst[10] = "1234";
// 	char src[10];
// 	// ft_strlcpy(NULL, NULL, 0);
// 	// ft_strlcpy(NULL, NULL, 1);
// 	// ft_strlcpy(dst, NULL, sizeof dst);
// 	// ft_strlcpy(dst, NULL, 0);
// 	// ft_strlcpy(NULL, src, sizeof dst);
// 	ft_strlcpy(NULL, src, 0);

// 	// strlcpy(NULL, NULL, 0);
// 	// strlcpy(NULL, NULL, 1);
// 	// strlcpy(dst, NULL, sizeof dst);
// 	// strlcpy(dst, NULL, 0);
// 	// strlcpy(NULL, src, sizeof dst);
// 	strlcpy(NULL, src, 0);
// }
