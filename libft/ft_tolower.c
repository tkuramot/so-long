/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:19:52 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 05:00:15 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c - 'A' + 'a');
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
