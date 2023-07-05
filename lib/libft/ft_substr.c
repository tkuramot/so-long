/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:54:05 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 19:27:20 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ret;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		len = 0;
	if (s_len < len)
		len = s_len;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	s += start;
	ft_strlcpy(ret, s, len + 1);
	return (ret);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s = "1234567890";
// 	printf("%s\n", ft_substr(s, 2, 5));
// }
