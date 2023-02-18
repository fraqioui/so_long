/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evolve_bonus_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:18:23 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/13 12:18:24 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long_bonus.h"

static	void	ft_move_check(t_map *map, int keycode)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 0 || keycode == 123)
	{
		ft_move(map, map->jp, map->ip - 1, keycode);
		map->flg = 1;
	}
	else if (keycode == 2 || keycode == 124)
	{
		ft_move(map, map->jp, map->ip + 1, keycode);
		map->flg = 0;
	}
	else if (keycode == 13 || keycode == 126)
		ft_move(map, map->jp - 1, map->ip, keycode);
	else if (keycode == 1 || keycode == 125)
		ft_move(map, map->jp + 1, map->ip, keycode);
}

int	f(int keycode, t_map *map)
{
	char	*s;

	ft_move_check(map, keycode);
	if (!mlx_clear_window(map->mlx_ptr, map->win_ptr))
		ft_map_free(map, "failed to clear window\n");
	if (!mlx_clear_window(map->mlx_ptr, map->win_ptr))
		ft_map_free(map, "failed to clear window\n");
	ft_put_img_to_window(map);
	s = ft_itoa(map->move);
	mlx_string_put(map->mlx_ptr, map->win_ptr, (map->width - 2) * 50,
		(map->height - 1) * 50, 0xb1d4e0, s);
	free(s);
	return (0);
}
