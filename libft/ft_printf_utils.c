/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 22:22:33 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/02 20:37:46 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_n(char c, size_t n)
{
	size_t	l;

	l = 0;
	while (n-- > 0)
		l += ft_putchar_r(c);
	return (l);
}

int	get_digit_count(unsigned long long nbr, size_t base)
{
	int	l;

	l = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		l++;
	}
	return (l);
}

static void	ft_putnbr_base_helper(unsigned long long nbr, char *base, size_t b)
{
	if (nbr >= (unsigned long long)b)
		ft_putnbr_base_helper(nbr / b, base, b);
	ft_putchar_r(base[nbr % b]);
}

size_t	ft_putnbr_base(unsigned long long nbr, char *base)
{
	size_t	b;
	size_t	l;

	b = ft_strlen(base);
	l = get_digit_count(nbr, b);
	ft_putnbr_base_helper(nbr, base, b);
	return (l);
}
