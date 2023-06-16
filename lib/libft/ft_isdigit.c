/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:12:55 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 04:32:35 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", isdigit('a'));
// 	printf("%d\n", isdigit('A'));
// 	printf("%d\n", isdigit('0'));
// 	printf("%d\n", isdigit(-1));

// 	printf("%d\n", ft_isdigit('a'));
// 	printf("%d\n", ft_isdigit('A'));
// 	printf("%d\n", ft_isdigit('0'));
// 	printf("%d\n", ft_isdigit(-1));
// }
