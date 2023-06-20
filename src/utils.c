/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:27:24 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/20 19:49:52 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**calloc_2d_array(size_t n_2d, size_t n_1d, size_t siz)
{
	void	**array;
	size_t	row_idx;

	array = (void **)ft_calloc(n_2d, sizeof (void *));
	row_idx = 0;
	while (row_idx < n_2d)
	{
		array[row_idx] = (void *)ft_calloc(n_1d, siz);
		if (!array[row_idx])
		{
			free_2d_array(array, row_idx);
			return (NULL);
		}
		row_idx++;
	}
	return (array);
}

void	free_2d_array(void **array, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
		free(array[idx++]);
	free(array);
}
