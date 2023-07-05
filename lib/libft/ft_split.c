/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 05:36:15 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 05:36:18 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_substr_num(char const *s, char c)
{
	int		is_word;
	size_t	cnt;

	is_word = (*s == c);
	cnt = 0;
	while (*s != '\0')
	{
		if (is_word && *s == c)
			is_word = 0;
		else if (!is_word && *s != c)
		{
			cnt++;
			is_word = 1;
		}
		s++;
	}
	return (cnt);
}

char	**free_all(char **result, size_t len)
{
	char	**tmp;

	tmp = result;
	while (len-- > 0)
		free(*tmp++);
	free(result);
	return (NULL);
}

static char	**ft_split_helper(char **result, char const *s, char c)
{
	char	**tmp;
	size_t	len;

	tmp = result;
	len = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			len = ft_strchr(s, c) - s;
			*tmp = ft_substr(s, 0, len);
			if (*tmp == NULL)
				return (free_all(result, (tmp - result) / sizeof(char *)));
		}
		while (*s != '\0' && *s != c)
			s++;
		tmp++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (s == NULL)
		return (NULL);
	result = ft_calloc(get_substr_num(s, c) + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	return (ft_split_helper(result, s, c));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char s[] = "   123444323         234s              ";
// 	char **res = ft_split(s, ' ');
// 	while(*res != NULL)
// 	{
// 		printf("%s\n", *res++);
// 	}
// 	return (0);
// }
