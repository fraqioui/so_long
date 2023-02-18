/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:56:58 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/12 12:56:59 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long_bonus.h"

static	void	ft_check_map(t_map *map, char **s)
{
	ft_check_ext(s[1]);
	ft_read_file(s[1], map);
	ft_check_rect(map);
	ft_check_limits(map);
	ft_check_map_ele(map);
	ft_copy_map(map);
	ft_check_ways(map);
	ft_evolve(map);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
		ft_check_map(&map, av);
	else
	{
		ft_printf("Error:\nUsage : ./so_long <filename>\n");
		return (1);
	}
	return (0);
}
