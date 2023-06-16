/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:59:02 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/03 22:21:11 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnstr_r(char *s, size_t n)
{
	size_t	ret;

	ret = n;
	while (n--)
		ft_putchar_r(*s++);
	return (ret);
}
