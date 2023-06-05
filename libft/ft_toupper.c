/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:18:34 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 05:00:46 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", tolower('b'));
// 	printf("%d\n", tolower('B'));
// 	printf("%d\n", tolower('9'));

// 	printf("%d\n", tolower('b'));
// 	printf("%d\n", tolower('B'));
// 	printf("%d\n", tolower('9'));
// }
