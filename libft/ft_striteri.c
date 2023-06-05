/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:05:44 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 04:50:48 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	idx;

	if (s == NULL || f == NULL)
		return ;
	idx = 0;
	while (*s != '\0')
		f(idx++, s++);
}

// #include <string.h>
// #include <stdio.h>

// void f(unsigned int i, char *s)
// {
// 	(void)i;
// 	*s = ft_toupper(*s);
// }

// int	main(void)
// {
// 	char s[] = "aaaaa";
// 	ft_striteri(s, f);
// 	printf("%s\n", s);
// }
