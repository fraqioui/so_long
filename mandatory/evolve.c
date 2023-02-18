/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evolve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:37:01 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/10 17:37:02 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long.h"

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
	if (!map->left || !map->left || !map->left || !map->left
		|| !map->left || !map->left || !map->left)
		ft_map_free(map, "failed to create image\n");
}

int	f(int keycode, t_map *map)
{
	int	i;

	i = 0;
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
	if (!mlx_clear_window(map->mlx_ptr, map->win_ptr))
		ft_map_free(map, "failed to clear window\n");
	ft_put_img_to_window(map);
	return (0);
}

int	distroy(t_map *map)
{
	ft_map_free(map, NULL);
	exit(1);
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
	map->move = 0;
	ft_printf("move: 0\n");
	ft_put_img_to_window(map);
	mlx_hook(map->win_ptr, 2, 0, f, map);
	mlx_hook(map->win_ptr, 17, 0, distroy, map);
	mlx_loop(map->mlx_ptr);
}
