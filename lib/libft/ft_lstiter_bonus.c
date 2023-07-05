/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:06:37 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/21 19:17:38 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <ctype.h>
// #include <stdio.h>

// void	f(void *p)
// {
// 	unsigned char *c = p;
// 	while(*c)
// 	 {
// 		*c = toupper(*c);
// 		c++;
// 	 }
// }

// int	main(void)
// {
// 	t_list *lst = ft_lstnew(ft_strdup("aa"));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("bb")));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("cc")));
// 	ft_lstiter(lst, f);
// 	for(t_list *node = lst; node != NULL; node = node->next)
// 	{
// 		printf("%s\n", (char *)node->content);
// 	}
// }
