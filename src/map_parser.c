/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:24:05 by tkuramot          #+#    #+#             */
/*   Updated: 2023/06/18 20:00:46 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// FREEEEEEEEEEE

static bool	put_map_together(t_map *map, char *row)
{
	size_t	index;
	char	**tmp;

	index = 0;
	tmp = map->grid;
	map->grid = (char **)malloc(sizeof (char *) * map->rows);
	if (!map->grid)
		return (false);
	while (index < map->rows)
	{
		map->grid[index] = ft_strdup(tmp[index]);
		if (!map->grid[index])
			return (false);
		index++;
	}
	map->grid[index] = row;
	return (true);
}

// Read map line by line till the eof
static t_map	*read_map(int fd)
{
	t_map	*map;
	char	*line;
	size_t	len;

	map = (t_map *)ft_calloc(1, sizeof (t_map));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map->rows++;
		len = ft_strlen_s(line);
		if (!len && len - 1 != map->columns)
			return (NULL);
		map->columns = len;
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (!put_map_together(map, line))
			return (NULL);
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
	if (!is_valid_map(map))
		return (NULL);
	return (map);
}
