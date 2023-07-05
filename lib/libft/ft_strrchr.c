/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:38:19 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/20 18:45:03 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*found;
	char	*p;

	if (c == '\0')
		return (ft_strchr(s, '\0'));
	found = NULL;
	p = ft_strchr(s, c);
	while (p != NULL)
	{
		found = p;
		s = p + 1;
		p = ft_strchr(s, c);
	}
	return (found);
}

// #include <string.h>

// int	main(void)
// {
// 	// ft_strrchr(NULL, 'a');
// 	strrchr(NULL, 'a');
// 	return 0;
// }
