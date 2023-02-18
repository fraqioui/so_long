/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:21:14 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/12 13:21:15 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long_bonus.h"

static	void	ft_fill_arr(char *file, t_map *map)
{
	int		fd;
	int		i;

	fd = ft_open(file);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
	{
		close(fd);
		ft_error("allocation failed\n");
	}
	i = -1;
	while (++i < map->height)
	{
		map->map[i] = get_next_line(fd);
		if (!map->map[i])
		{
			ft_alloc_fail(map->map);
			close(fd);
			ft_error("allocation failure\n");
		}
	}
	map->map[i] = NULL;
	close(fd);
}

void	ft_read_file(char *file, t_map *map)
{
	map->width = ft_get_width(file);
	if (!map->width)
		ft_error("allocation failure\n");
	map->height = ft_get_height(file, map->width);
	if (!map->height)
		ft_error("allocation failure\n");
	ft_fill_arr(file, map);
}
