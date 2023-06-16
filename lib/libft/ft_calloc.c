/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:29:35 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 04:16:58 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*b;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	b = malloc(count * size);
	if (b == NULL)
		return (b);
	ft_bzero(b, count * size);
	return (b);
}

// #include <stdlib.h>
// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	void *ptr;
// 	ptr = ft_calloc(0, 0);
// 	ptr = ft_calloc(SIZE_MAX / 10, SIZE_MAX / 10 + 1);
// 	ptr = calloc(0, 0);
// 	ptr = calloc(SIZE_MAX / 10, SIZE_MAX / 10 + 1);
// }
