/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:20:35 by fraqioui          #+#    #+#             */
/*   Updated: 2023/02/12 13:20:36 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long_bonus.h"

void	ft_error(char	*s)
{
	if (s)
	{
		ft_printf("Error\n");
		ft_printf("%s", s);
	}
	exit(1);
}

int	ft_cmp(char *a, char *b)
{
	size_t	na;
	size_t	nb;
	int		i;

	i = 0;
	na = ft_strlen(a) - 1;
	nb = ft_strlen(b) - 1;
	if (na < nb)
		return (1);
	while (i++ < 4)
	{
		if (a[na] != b[nb])
			return (1);
		na--;
		nb--;
	}
	return (0);
}

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
	{
		perror("");
		exit(1);
	}
	return (fd);
}

int	ft_get_width(char	*file)
{
	char	*s;
	int		i;
	int		fd;

	fd = ft_open(file);
	s = get_next_line(fd);
	if (!s)
	{
		close(fd);
		ft_error("empty file\n");
	}
	i = ft_strlen(s);
	close(fd);
	free(s);
	return (i);
}

int	ft_get_height(char	*file, int width)
{
	char	*s;
	int		i;
	int		fd;

	i = 0;
	fd = ft_open(file);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		if ((ft_strlen(s) != (size_t)width)
			&& (ft_strlen(s) != (size_t)width - 1))
		{
			close(fd);
			free(s);
			ft_error("Found wrong line length. Exiting.");
		}
		i++;
		free(s);
	}
	close(fd);
	return (i);
}
