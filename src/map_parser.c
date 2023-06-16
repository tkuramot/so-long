/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:24:05 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/16 13:16:08 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Read map line by line till the eof
static t_map	*read_map(int fd)
{
	t_map	*map;
	char	*line;

	map = (t_map *)ft_calloc(1, sizeof (t_map));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (!line)
	{
		ft_lstadd_back(map->grid, ft_lstnew(line));
		line = get_next_line(fd);
	}
	return (map);
}

t_map	*parse_map(char *map_file)
{
	int		fd;
	t_map	*map;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = read_map(fd);
	count_rows_and_columns(map);
	if (!is_valid_map(map))
		return (NULL);
	return (map);
}
