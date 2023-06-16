/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:12:13 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 19:17:58 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	sz;

	sz = 0;
	if (lst == NULL)
		return (sz);
	while (lst != NULL)
	{
		lst = lst->next;
		sz++;
	}
	return (sz);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list *lst = ft_lstnew("aa");
// 	ft_lstadd_front(&lst, ft_lstnew("bb"));
// 	printf("%d\n", ft_lstsize(lst));
// }
