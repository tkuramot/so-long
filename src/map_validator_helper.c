/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:51:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/16 15:23:41 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	has_same_chars(char *s, char c)
{
	bool	is_same;

	is_same = true;
	while (*s)
	{
		is_same &= (*s == c);
		s++;
	}
	return (is_same);
}

bool	is_surrounded_by_walls(t_map *map)
{
	t_list	*top;
	t_list	*bottom;
	bool	is_surrounded;

	top = *(map->grid);
	bottom = ft_lstlast(top);
	is_surrounded = true;
	is_surrounded &= has_same_chars((char *)top, WALL);
	is_surrounded &= has_same_chars((char *)bottom, WALL);
	while (top)
	{
		is_surrounded &= (((char *)top)[0] == WALL);
		is_surrounded &= (((char *)top)[map->columns - 1] == WALL);
		top = top->next;
	}
	return (is_surrounded);
}

// Check whether the goal is reachable and
// the collectible is collectible
bool	is_playable(t_map *map)
{
	(void)map;
	return (true);
}
