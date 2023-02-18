/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evolve_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:21:33 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/12 13:21:34 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long_bonus.h"

static	void	ft_to_images(t_map	*map)
{
	int		img_width;
	int		img_height;

	map->left = mlx_xpm_file_to_image(map->mlx_ptr, "images/left.xpm",
			&img_width, &img_height);
	map->right = mlx_xpm_file_to_image(map->mlx_ptr, "images/right.xpm",
			&img_width, &img_height);
	map->background = mlx_xpm_file_to_image(map->mlx_ptr,
			"images/background.xpm", &img_width, &img_height);
	map->eat = mlx_xpm_file_to_image(map->mlx_ptr, "images/eat.xpm",
			&img_width, &img_height);
	map->open = mlx_xpm_file_to_image(map->mlx_ptr, "images/open.xpm",
			&img_width, &img_height);
	map->close = mlx_xpm_file_to_image(map->mlx_ptr, "images/close.xpm",
			&img_width, &img_height);
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr, "images/wall.xpm",
			&img_width, &img_height);
	map->on = mlx_xpm_file_to_image(map->mlx_ptr, "images/on.xpm",
			&img_width, &img_height);
	map->off = mlx_xpm_file_to_image(map->mlx_ptr, "images/off.xpm",
			&img_width, &img_height);
	if (!map->left || !map->left || !map->left || !map->left
		|| !map->left || !map->left || !map->left || !map->on || !map->off)
		ft_map_free(map, "failed to create image\n");
}

int	distroy(t_map *map)
{
	ft_map_free(map, NULL);
	exit(1);
}

int	ptr(t_map *map)
{
	static int	k;

	if (k < 1000)
		k++;
	else
	{
		k = 0;
		if (!mlx_clear_window(map->mlx_ptr, map->win_ptr))
			ft_map_free(map, "faile to clear window\n");
		ft_put_img_to_window(map);
	}
	return (0);
}

void	ft_evolve(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		ft_map_free(map, "failed to  initialize the display\n");
	map->win_ptr = mlx_new_window(map->mlx_ptr, (map->width - 1) * 50,
			map->height * 50, "SO_LONG");
	if (!map->win_ptr)
		ft_map_free(map, "failed to create a new window\n");
	ft_to_images(map);
	map->flg = 1;
	map->_flg = 1;
	map->move = 0;
	ft_put_img_to_window(map);
	mlx_hook(map->win_ptr, 2, 0, f, map);
	mlx_loop_hook(map->mlx_ptr, ptr, map);
	mlx_hook(map->win_ptr, 17, 0, distroy, map);
	mlx_loop(map->mlx_ptr);
}
