/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:02:38 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/09 15:02:40 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long.h"

void	ft_check_ext(char *file)
{
	if (ft_cmp(file, ".ber"))
		ft_error("invalid extension\n");
}

void	ft_check_rect(t_map *map)
{
	if (map->height >= map->width)
		ft_map_free(map, "not rectangular\n");
}

static	void	ft_check(t_map *map, int k, int h)
{
	if (map->map[k][h] == 'C')
		map->c++;
	else if (map->map[k][h] == 'E')
	{
		map->e++;
		map->ie = h;
		map->je = k;
	}
	else if (map->map[k][h] == 'P')
	{
		map->p++;
		map->ip = h;
		map->jp = k;
	}
}

static	void	ft_while(t_map *map, int k)
{
	int	h;

	h = 0;
	while (++h < map->width - 2)
	{
		if (map->map[k][h] != 'C' && map->map[k][h] != 'E'
				&& map->map[k][h] != '0' && map->map[k][h] != 'P'
						&& map->map[k][h] != '1')
			ft_map_free(map, "invalid map\n");
		ft_check(map, k, h);
	}
}

void	ft_check_map_ele(t_map *map)
{
	int	k;

	k = 0;
	map->p = 0;
	map->e = 0;
	map->c = 0;
	while (++k < map->height - 1)
		ft_while (map, k);
	if (map->p != 1 || map->e != 1 || map->c < 1)
		ft_map_free(map, "invalid map\n");
}
