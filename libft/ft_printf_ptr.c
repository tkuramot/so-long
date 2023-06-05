/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:51:35 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/31 17:16:50 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_ptr(unsigned long long ptr, t_placeholder ph)
{
	size_t	l;

	l = 0;
	if (!(ph.flags & HYPHEN) && get_digit_count(ptr, 16) + 2 < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - get_digit_count(ptr, 16) - 2);
	l += ft_putstr_r("0x");
	l += ft_putnbr_base(ptr, HEXADECIMAL_L);
	if ((ph.flags & HYPHEN) && get_digit_count(ptr, 16) + 2 < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - get_digit_count(ptr, 16) - 2);
	return (l);
}
