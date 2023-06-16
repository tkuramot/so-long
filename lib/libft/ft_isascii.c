/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:24:39 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 04:30:56 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", isascii('a'));
// 	printf("%d\n", isascii('A'));
// 	printf("%d\n", isascii('0'));
// 	printf("%d\n", isascii(-1));

// 	printf("%d\n", ft_isascii('a'));
// 	printf("%d\n", ft_isascii('A'));
// 	printf("%d\n", ft_isascii('0'));
// 	printf("%d\n", ft_isascii(-1));
// }
