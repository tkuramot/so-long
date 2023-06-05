/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:26:56 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 04:33:35 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", isprint('a'));
// 	printf("%d\n", isprint('A'));
// 	printf("%d\n", isprint('0'));
// 	printf("%d\n", isprint(-1));

// 	printf("%d\n", ft_isprint('a'));
// 	printf("%d\n", ft_isprint('A'));
// 	printf("%d\n", ft_isprint('0'));
// 	printf("%d\n", ft_isprint(-1));
// }
