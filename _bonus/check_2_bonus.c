/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:19:50 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/12 13:19:51 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long_bonus.h"

void	ft_check_limits(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (map->map[i][0] != '1' || (map->map[i][map->width - 1] != '1'
				&& map->map[i][map->width - 2] != '1'))
			ft_map_free(map, "invalid map\n");
		i++;
	}
	i = 0;
	while (map->map[map->height - 1][i])
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			ft_map_free(map, "invalid map\n");
		i++;
	}
}

void	dfs(t_map *map, int i, int j)
{
	if (map->c_map[j][i] == 'E' || map->c_map[j][i] == '1'
			|| map->c_map[j][i] == 'F' || map->c_map[j][i] == 'N')
		return ;
	map->c_map[j][i] = 'F';
	dfs(map, i + 1, j);
	dfs(map, i - 1, j);
	dfs(map, i, j + 1);
	dfs(map, i, j - 1);
}

static	int	ft_check(t_map *map, int i, int j)
{
	if (map->c_map[i + 1][j] == 'F' || map->c_map[i - 1][j] == 'F' ||
			map->c_map[i][j + 1] == 'F' || map->c_map[i][j - 1] == 'F')
		return (0);
	return (1);
}

static	int	ft_c(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->c_map[++i])
	{
		j = 0;
		while (map->c_map[i][++j])
		{
			if (map->c_map[i][j] == 'C')
				return (1);
		}
	}
	return (0);
}

void	ft_check_ways(t_map *map)
{
	dfs(map, map->ip, map->jp);
	if (ft_check(map, map->je, map->ie) || ft_c(map))
	{
		ft_alloc_fail(map->c_map);
		ft_map_free(map, "invalid path\n");
	}
	ft_alloc_fail(map->c_map);
}
