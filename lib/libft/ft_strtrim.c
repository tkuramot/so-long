/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:53:56 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 04:56:48 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_charset(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*tmp;
	size_t	total_len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 != '\0' && is_in_charset(*s1, set))
		s1++;
	total_len = ft_strlen(s1);
	tmp = (char *)s1 + total_len - 1;
	while (*s1 != '\0' && is_in_charset(*tmp, set))
	{
		total_len--;
		tmp--;
	}
	ret = (char *)malloc(sizeof(char) * (total_len + 1));
	if (ret == NULL)
		return (NULL);
	tmp = ret;
	while (total_len-- > 0)
		*tmp++ = *s1++;
	*tmp = '\0';
	return (ret);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char s[] = "   a a a 3127890 a aaa  ";
// 	printf("%s\n", ft_strtrim(s, " a"));
// }
