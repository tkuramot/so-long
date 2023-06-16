/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:27:12 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 05:07:09 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (lst == NULL || new == NULL)
		return ;
	last_node = ft_lstlast(*lst);
	if (last_node == NULL)
	{
		*lst = new;
		return ;
	}
	last_node->next = new;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list *lst = ft_lstnew("aa");
// 	ft_lstadd_back(&lst, ft_lstnew("bb"));
// 	printf("%s\n", lst->next->content);
// }
