/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:28:01 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/03 22:28:02 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_placeholder	get_output_length(char *s, t_placeholder ph)
{
	size_t	l;

	l = ft_strlen(s);
	if (ph.precision != -1 && ph.precision < (long long)l)
		ph.len = ph.precision;
	else
		ph.len = l;
	return (ph);
}

size_t	ft_printf_str(char *s, t_placeholder ph)
{
	size_t	l;

	l = 0;
	if (!s)
		return (ft_printf_str("(null)", ph));
	ph = get_output_length(s, ph);
	if (!(ph.flags & HYPHEN) && ph.len < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - ph.len);
	if (ph.precision != -1 && ph.precision < (long long)ft_strlen(s))
		l += ft_putnstr_r(s, ph.precision);
	else
		l += ft_putstr_r(s);
	if ((ph.flags & HYPHEN) && ph.len < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - ph.len);
	return (l);
}
