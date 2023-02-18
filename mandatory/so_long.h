/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:19:50 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/09 14:19:51 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include<mlx.h>
# include<math.h>
# include<fcntl.h>
# include<stdio.h>
# include"../get_next_line/get_next_line.h"
# include"../ft_printf/ft_printf.h"

typedef struct s_map
{
	int		height;
	int		width;
	char	**map;
	char	**c_map;
	int		ip;
	int		jp;
	int		ie;
	int		je;
	int		c;
	int		e;
	int		p;
	int		flg;
	int		move;
	void	*left;
	void	*right;
	void	*background;
	void	*eat;
	void	*open;
	void	*close;
	void	*wall;
	void	*mlx_ptr;
	void	*win_ptr;
}t_map;

int		ft_words(const char *s2, char c);
char	**ft_split(char const *s, char c);
void	ft_error(char *s);
int		ft_cmp(char *a, char *b);
char	**ft_alloc_fail(char **arr);
void	ft_check_ext(char *file);
void	ft_check_rect(t_map *map);
void	ft_check_limits(t_map *map);
void	ft_check_map_ele(t_map *map);
void	ft_check_ways(t_map *map);
void	ft_read_file(char *file, t_map *map);
int		ft_get_width(char	*file);
int		ft_get_height(char	*file, int width);
int		ft_open(char *file);
void	dfs(t_map *map, int i, int j);
void	ft_copy_map(t_map *map);
void	ft_evolve(t_map *map);
int		f(int keycode, t_map *map);
void	ft_put_img_to_window(t_map *map);
void	ft_move(t_map *map, int j, int i, int key);
void	ft_map_free(t_map *map, char *s);

#endif
