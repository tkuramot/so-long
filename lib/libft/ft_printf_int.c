/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:31:15 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/31 17:43:35 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	ft_abs(long long *nbr)
{
	bool	is_neg;

	is_neg = *nbr < 0;
	if (is_neg)
		*nbr *= -1;
	return (is_neg);
}

static size_t	print_sign(bool is_neg, t_placeholder ph)
{
	size_t	l;

	l = 0;
	if (is_neg)
	{
		l += ft_putchar_r('-');
	}
	else
	{
		if (ph.flags & PLUS)
			l += ft_putchar_r('+');
		else if (ph.flags & SPACE)
			l += ft_putchar_r(' ');
	}
	return (l);
}

static t_placeholder	get_output_length(long long digit, t_placeholder ph)
{
	if (ph.precision != -1 && ph.precision > digit)
		ph.len = ph.precision;
	else
		ph.len = digit;
	return (ph);
}

static t_placeholder	adjust_padding(long long nbr, t_placeholder ph)
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

size_t	ft_printf_int(long long nbr, t_placeholder ph)
{
	size_t		l;
	long long	digit;
	bool		is_neg;

	l = 0;
	is_neg = ft_abs(&nbr);
	digit = get_digit_count(nbr, 10);
	ph = get_output_length(digit, ph);
	ph = adjust_padding(nbr, ph);
	if (!(ph.flags & HYPHEN) && !(ph.flags & ZERO) && ph.len < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - ph.len - is_neg);
	l += print_sign(is_neg, ph);
	if (!(ph.flags & HYPHEN) && (ph.flags & ZERO) && ph.len < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - ph.len - is_neg);
	if (digit < ph.precision)
		l += ft_putchar_n('0', ph.precision - digit);
	if (!nbr && !ph.precision && ph.width != -1)
		l += ft_putchar_r(' ');
	else if (!nbr && !ph.precision)
		l += 0;
	else
		l += ft_putnbr_base(nbr, DECIMAL);
	if ((ph.flags & HYPHEN) && !(ph.flags & ZERO) && ph.len < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - ph.len - is_neg);
	return (l);
}
