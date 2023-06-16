/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:16:41 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 19:20:40 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_helper(int n, int fd, int is_negative)
{
	char	c;

	if (is_negative)
		c = -(n % 10) + '0';
	else
		c = (n % 10) + '0';
	if (!(!is_negative && n < 10) && !(is_negative && n > -10))
	{
		ft_putnbr_fd_helper(n / 10, fd, is_negative);
	}
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	ft_putnbr_fd_helper(n, fd, n < 0);
}

// int	main(void)
// {
// 	ft_putnbr_fd(1231890, 1);
// 	ft_putnbr_fd(-1231890, 1);
// }
