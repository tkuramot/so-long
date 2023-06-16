/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:30:19 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/20 18:44:48 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// #include <string.h>

// int	main(void)
// {
// 	char s1[10] = "1234";
// 	char s2[10] = "1233";
// 	(void)s1;
// 	(void)s2;
// 	ft_strncmp(NULL, NULL, 0);
// 	// ft_strncmp(NULL, NULL, 1);
// 	// ft_strncmp(s1, NULL, 0);
// 	// ft_strncmp(s1, NULL, 1);
// 	// ft_strncmp(NULL, s2, 0);
// 	// ft_strncmp(NULL, s2, 1);

// 	// strncmp(NULL, NULL, 0);
// 	// strncmp(NULL, NULL, 1);
// 	// strncmp(s1, NULL, 0);
// 	// strncmp(s1, NULL, 1);
// 	// strncmp(NULL, s2, 0);
// 	// strncmp(NULL, s2, 1);
// }
