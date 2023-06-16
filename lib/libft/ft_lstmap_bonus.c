/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:28:39 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 05:35:33 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	if (result == NULL)
		return (NULL);
	tmp = result;
	while (lst->next != NULL)
	{
		lst = lst->next;
		tmp->next = ft_lstnew(f(lst->content));
		if (tmp->next == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (result);
}

// #include <ctype.h>
// #include <stdio.h>

// void	*f(void *p)
// {
// 	(void)p;
// 	return ft_strdup("aaaaaaa");
// }

// int	main(void)
// {
// 	t_list *lst = ft_lstnew(ft_strdup("aa"));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("bb")));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("cc")));
// 	lst = ft_lstmap(lst, f, free);
// 	for(t_list *node = lst; node != NULL; node = node->next)
// 	{
// 		printf("%s\n", (char *)node->content);
// 	}
// }
