/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:30:09 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/02 19:32:14 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_percent(t_placeholder ph)
{
	size_t	l;

	l = 0;
	if (!(ph.flags & HYPHEN) && ph.width > 1)
		l += ft_putchar_n(ph.padding, ph.width - 1);
	l += ft_putchar_r('%');
	if ((ph.flags & HYPHEN) && ph.width > 1)
		l += ft_putchar_n(ph.padding, ph.width - 1);
	return (l);
}
