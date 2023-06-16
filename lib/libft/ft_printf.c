/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:16:58 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/03 22:09:46 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*parse_number(const char *fmt, t_placeholder *ph, char type)
{
	if (type == 'p')
	{
		ph->precision = 0;
		while (*fmt && ft_isdigit(*fmt))
			ph->precision = ph->precision * 10 + (*fmt++ - '0');
	}
	else if (type == 'w')
	{
		if (*fmt && ft_isdigit(*fmt))
			ph->width = 0;
		while (*fmt && ft_isdigit(*fmt))
			ph->width = ph->width * 10 + (*fmt++ - '0');
	}
	return (fmt);
}

static int	ft_vprintf(va_list *ap, t_placeholder ph)
{
	size_t	l;

	l = 0;
	if (ph.type == CHAR)
		l += ft_printf_char((char)va_arg(*ap, int), ph);
	else if (ph.type == STR)
		l += ft_printf_str(va_arg(*ap, char *), ph);
	else if (ph.type == PTR)
		l += ft_printf_ptr(va_arg(*ap, unsigned long long), ph);
	else if (ph.type == DEC)
		l += ft_printf_int(va_arg(*ap, int), ph);
	else if (ph.type == INT)
		l += ft_printf_int(va_arg(*ap, int), ph);
	else if (ph.type == U_DEC)
		l += ft_printf_uint(va_arg(*ap, unsigned int), ph);
	else if (ph.type == HEX_L)
		l += ft_printf_lower_hex(va_arg(*ap, unsigned int), ph);
	else if (ph.type == HEX_U)
		l += ft_printf_upper_hex(va_arg(*ap, unsigned int), ph);
	else if (ph.type == PERCENT)
		l += ft_printf_percent(ph);
	return (l);
}

static const char	*parse_flags(const char *fmt, t_placeholder *ph)
{
	while (ft_strchr(FLAGS, *fmt))
	{
		if (*fmt == '-')
			ph->flags |= HYPHEN;
		else if (*fmt == '0')
		{
			ph->flags |= ZERO;
			ph->padding = '0';
		}
		else if (*fmt == '#')
			ph->flags |= HASH;
		else if (*fmt == ' ')
			ph->flags |= SPACE;
		else if (*fmt == '+')
			ph->flags |= PLUS;
		fmt++;
	}
	return (fmt);
}

static const char	*parse_placeholder(const char *fmt, t_placeholder *ph)
{
	fmt = parse_flags(fmt, ph);
	fmt = parse_number(fmt, ph, 'w');
	if (*fmt && *fmt == '.')
		fmt = parse_number(++fmt, ph, 'p');
	if (*fmt && *fmt == 'c')
		ph->type = CHAR;
	else if (*fmt && *fmt == 's')
		ph->type = STR;
	else if (*fmt && *fmt == 'p')
		ph->type = PTR;
	else if (*fmt && *fmt == 'd')
		ph->type = DEC;
	else if (*fmt && *fmt == 'i')
		ph->type = INT;
	else if (*fmt && *fmt == 'u')
		ph->type = U_DEC;
	else if (*fmt && *fmt == 'x')
		ph->type = HEX_L;
	else if (*fmt && *fmt == 'X')
		ph->type = HEX_U;
	else if (*fmt && *fmt == '%')
		ph->type = PERCENT;
	return (++fmt);
}

int	ft_printf(const char *fmt, ...)
{
	va_list			ap;
	size_t			l;
	t_placeholder	ph;

	l = 0;
	va_start(ap, fmt);
	if (!fmt)
		return (0);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			ph.flags = 0;
			ph.width = -1;
			ph.precision = -1;
			ph.type = -1;
			ph.padding = ' ';
			fmt = parse_placeholder(++fmt, &ph);
			l += ft_vprintf(&ap, ph);
		}
		else
			l += ft_putchar_r(*fmt++);
	}
	va_end(ap);
	return (l);
}
