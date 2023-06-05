/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:49:18 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/03 21:56:58 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_char(char c, t_placeholder ph)
{
	size_t	l;

	l = 0;
	if (!(ph.flags & HYPHEN) && ph.width != -1)
		l += ft_putchar_n(ph.padding, ph.width - 1);
	l += ft_putchar_r(c);
	if ((ph.flags & HYPHEN) && ph.width != -1)
		l += ft_putchar_n(ph.padding, ph.width - 1);
	return (l);
}
