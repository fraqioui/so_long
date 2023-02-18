/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_Line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:55:10 by fraqioui          #+#    #+#             */
/*   Updated: 2022/11/01 11:14:30 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char *s, unsigned int index, size_t len);
char	*ft_get_the_line(int fd, char **str, char *buf);
ssize_t	ft_check_new_line(char *s1);
char	*ft_save(char **s3, size_t n);
char	*ft_free(char **s, char *set);
char	*ft_new_line(char **s2);

#endif
