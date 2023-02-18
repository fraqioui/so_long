/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:21:02 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/12 13:21:03 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long_bonus.h"

static	void	ft_check(t_map *map, int key)
{
	if (key == 0 || key == 123)
		map->ip--;
	else if (key == 2 || key == 124)
		map->ip++;
	else if (key == 13 || key == 126)
		map->jp--;
	else if (key == 1 || key == 125)
		map->jp++;
}

void	ft_move(t_map *map, int j, int i, int key)
{
	if (map->map[j][i] == '0' || map->map[j][i] == 'C')
	{
		if (map->map[j][i] == 'C')
			map->c--;
		map->map[map->jp][map->ip] = '0';
		map->map[j][i] = 'P';
		map->move++;
		ft_check(map, key);
	}
	else if ((map->map[j][i] == 'E' && !map->c) || map->map[j][i] == 'N')
		ft_map_free(map, NULL);
}

static	void	ft_1(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall,
			j * 50, i * 50);
	if (map->map[i][j] == '0')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->background, j * 50, i * 50);
	if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->eat,
			j * 50, i * 50);
	if (map->map[i][j] == 'N')
	{
		if (map->_flg)
		{
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->on,
				j * 50, i * 50);
		}
		else
		{
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->off,
				j * 50, i * 50);
		}
	}
	return ;
}

static	void	ft_2(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'E')
	{
		if (map->c == 0)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->open,
				j * 50, i * 50);
		else
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->close,
				j * 50, i * 50);
	}
	if (map->map[i][j] == 'P')
	{
		if (map->flg == 0)
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->right,
				j * 50, i * 50);
		else
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->left,
				j * 50, i * 50);
	}
	return ;
}

void	ft_put_img_to_window(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = map->width;
	while (++i < map->height)
	{
		j = -1;
		if (i == map->height - 1)
			k = map->width - 2;
		while (++j < k)
		{
			ft_1(map, i, j);
			ft_2(map, i, j);
		}
	}
	if (map->_flg)
		map->_flg = 0;
	else
		map->_flg = 1;
}
