/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lower_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:53:42 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/03 21:57:51 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_placeholder	get_output_length(unsigned long long digit,
		t_placeholder ph)
{
	if (ph.precision != -1 && ph.precision > (long long)digit)
		ph.len = ph.precision;
	else
		ph.len = digit;
	if (ph.flags & HASH)
		ph.len += 2;
	return (ph);
}

static t_placeholder	adjust_padding(unsigned long long nbr, t_placeholder ph)
{
	if (!nbr && !ph.precision && (ph.flags & ZERO))
		ph.padding = ' ';
	if (ph.precision != -1 && (ph.flags & ZERO))
	{
		ph.padding = ' ';
		ph.flags ^= ZERO;
	}
	return (ph);
}

size_t	ft_printf_lower_hex(unsigned long long nbr, t_placeholder ph)
{
	size_t		l;
	long long	digit;

	l = 0;
	digit = get_digit_count(nbr, 16);
	ph = get_output_length(digit, ph);
	ph = adjust_padding(nbr, ph);
	if (!(ph.flags & HYPHEN) && !(ph.flags & ZERO) && ph.len < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - ph.len);
	if (nbr && ph.flags & HASH)
		l += ft_putstr_r("0x");
	if (!(ph.flags & HYPHEN) && (ph.flags & ZERO) && ph.len < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - ph.len);
	if (digit < ph.precision)
		l += ft_putchar_n('0', ph.precision - digit);
	if (!nbr && !ph.precision && ph.width != -1)
		l += ft_putchar_r(' ');
	else if (!nbr && !ph.precision)
		l += 0;
	else
		l += ft_putnbr_base(nbr, HEXADECIMAL_L);
	if ((ph.flags & HYPHEN) && ph.len < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - ph.len);
	return (l);
}
