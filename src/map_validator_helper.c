/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:51:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/16 16:33:07 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	has_same_chars(char *s, char c)
{
	while (*s)
	{
		if (*s != c)
			return (false);
		s++;
	}
	return (true);
}

bool	is_surrounded_by_walls(t_map *map)
{
	t_list	*top;
	t_list	*bottom;

	top = map->grid;
	bottom = ft_lstlast(top);
	if (!has_same_chars((char *)top->content, WALL)
		|| !has_same_chars((char *)bottom->content, WALL))
		return (false);
	while (top)
	{
		if ((((char *)top)[0] == WALL)
			|| (((char *)top)[map->columns - 1] == WALL))
			return (false);
		top = top->next;
	}
	return (true);
}

// Check whether the goal is reachable and
// the collectible is collectible
bool	is_playable(t_map *map)
{
	(void)map;
	return (true);
}
