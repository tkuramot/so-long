/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:54:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 04:04:28 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_overflow(long *nb, int digit, int sign)
{
	if (*nb * sign > LONG_MAX / 10 || (*nb * sign == LONG_MAX / 10
			&& digit > LONG_MAX % 10))
	{
		*nb = LONG_MAX;
		return (1);
	}
	if (*nb * sign < LONG_MIN / 10 || (*nb * sign == LONG_MIN / 10 && digit
			> -(LONG_MIN % 10)))
	{
		*nb = LONG_MIN;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (handle_overflow(&nb, *str - '0', sign))
			break ;
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return ((int)(nb * sign));
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_atoi("   +1234"));
// 	printf("%d\n", ft_atoi("   -12 34"));
// 	printf("%d\n", ft_atoi("   + 1234"));
// 	printf("%d\n", ft_atoi("   +2147483647"));
// 	printf("%d\n", ft_atoi("   -2147483647"));

// 	printf("%d\n", atoi("   +1234"));
// 	printf("%d\n", atoi("   -12 34"));
// 	printf("%d\n", atoi("   + 1234"));
// 	printf("%d\n", atoi("   +2147483647"));
// 	printf("%d\n", atoi("   -2147483648"));
// }
