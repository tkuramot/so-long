/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:20:46 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/20 18:43:53 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		ret = (char *)s;
	return (ret);
}

// #include <string.h>

// int	main(void)
// {
// 	// ft_strchr(NULL, 'a');
// 	strchr(NULL, 'a');
// 	return 0;
// }
