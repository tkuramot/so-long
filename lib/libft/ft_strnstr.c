/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:23:28 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/20 18:44:59 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare(const char *s1, const char *s2, size_t len)
{
	while (*s1 != '\0' && *s2 != '\0' && len > 0)
	{
		if (*s1 != *s2)
		{
			return (0);
		}
		s1++;
		s2++;
		len--;
	}
	return (*s2 == '\0');
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *)haystack);
	while (len > 0 && *haystack != '\0')
	{
		if ((*haystack == *needle) && compare(haystack, needle, len))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

// #include <string.h>

// int	main(void)
// {
// 	char haystack[10] = "123456";
// 	char needle[10] = "3";
// 	// ft_strnstr(NULL, NULL, 0);
// 	// ft_strnstr(NULL, NULL, 1);
// 	// ft_strnstr(haystack, NULL, 0);
// 	// ft_strnstr(haystack, NULL, 0);
// 	ft_strnstr(NULL, needle, 0);
// 	// ft_strnstr(NULL, needle, 1);

// 	// strnstr(NULL, NULL, 0);
// 	// strnstr(NULL, NULL, 1);
// 	// strnstr(haystack, NULL, 0);
// 	// strnstr(haystack, NULL, 0);
// 	strnstr(NULL, needle, 0);
// 	// strnstr(NULL, needle, 1);
// }
