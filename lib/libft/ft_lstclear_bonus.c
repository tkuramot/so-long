/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:59:32 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 05:12:34 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur_node;
	t_list	*nex_node;

	if (lst == NULL || del == NULL)
		return ;
	cur_node = *lst;
	while (cur_node != NULL)
	{
		nex_node = cur_node->next;
		ft_lstdelone(cur_node, del);
		cur_node = nex_node;
	}
	*lst = NULL;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list *lst = ft_lstnew(ft_strdup("aa"));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("bb")));
// 	ft_lstclear(&lst, free);
// }
