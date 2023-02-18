/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:20:48 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/12 13:20:49 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long_bonus.h"

void	ft_map_free(t_map *map, char *s)
{
	ft_alloc_fail(map->map);
	ft_error(s);
}

static	char	*ft_strcpy(t_map *map, char *src)
{
	int		i;
	char	*dst;

	i = -1;
	dst = malloc(sizeof(char) * (map->width + 1));
	if (!dst)
		return (NULL);
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

void	ft_copy_map(t_map *map)
{
	int	i;

	i = -1;
	map->c_map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->c_map)
		ft_map_free(map, "allocation failure\n");
	while (map->map[++i])
	{
		map->c_map[i] = ft_strcpy(map, map->map[i]);
		if (!map->c_map[i])
		{
			ft_alloc_fail(map->c_map);
			ft_map_free(map, "alloaction failure\n");
		}
	}
	map->c_map[i] = NULL;
}
