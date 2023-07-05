/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:33:59 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 19:30:47 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_number_of_digits(int n)
{
	size_t	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*ret;
	char	*tmp;
	size_t	len;
	int		is_negative;

	is_negative = (n < 0);
	len = get_number_of_digits(n);
	ret = (char *)malloc(sizeof(char) * (len + is_negative + 1));
	if (ret == NULL)
		return (NULL);
	tmp = ret + len + is_negative;
	*tmp-- = '\0';
	while (len-- > 0)
	{
		if (!is_negative)
			*tmp-- = (n % 10) + '0';
		else
			*tmp-- = -(n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		*tmp = '-';
	return (ret);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(2147483647));
// 	printf("%s\n", ft_itoa(-2147483648));
// 	printf("%s\n", ft_itoa(-2));
// 	printf("%s\n", ft_itoa(0));
// }
