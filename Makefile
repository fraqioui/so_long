# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 14:19:39 by fraqioui          #+#    #+#              #
#    Updated: 2023/02/09 14:19:41 by fraqioui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
FALGS = -Wall -Wextra -Werror
HEADER = mandatory/so_long.h get_next_line/get_next_line.h ft_printf/ft_printf.h 
BHEADER = _bonus/so_long_bonus.h get_next_line/get_next_line.h ft_printf/ft_printf.h 
RM = rm -rf 
MLX =  -lmlx -framework OpenGL -framework AppKit

FILES = mandatory/main \
		mandatory/utils_1 \
		mandatory/utils_2 \
		mandatory/utils_3 \
		mandatory/check_1 \
		mandatory/check_2 \
		mandatory/read_file \
		mandatory/evolve \
		mandatory/moves \
		ft_printf/start \
		ft_printf/hex \
		ft_printf/number \
		ft_printf/string \
		get_next_line/get_next_line \
		get_next_line/get_next_line_utils \

BFILES = _bonus/_bonus \
		_bonus/utils_1_bonus \
		_bonus/utils_2_bonus \
		_bonus/utils_3_bonus \
		_bonus/check_1_bonus \
		_bonus/check_2_bonus \
		_bonus/utils_4_bonus \
		_bonus/read_file_bonus \
		_bonus/evolve_bonus \
		_bonus/evolve_bonus_1 \
		_bonus/moves_bonus \
		ft_printf/start \
		ft_printf/hex \
		ft_printf/number \
		ft_printf/string \
		get_next_line/get_next_line \
		get_next_line/get_next_line_utils \

FOBJ = ${FILES:=.o}
BOBJ = ${BFILES:=.o}
BONUS_NAME = so_long_bonus

all: ${NAME}

bonus: ${BONUS_NAME}

${BONUS_NAME}: ${BOBJ}  ${BHEADER}
	${CC} ${FALGS} ${MLX} ${BOBJ} -o $@

${NAME}: ${FOBJ} ${HEADER}
	${CC} ${FALGS} ${MLX} ${FOBJ} -o $@

%.o: %.c
	${CC} ${FALGS} -c $< -o $@

clean:
	${RM} ${FOBJ} ${BOBJ}

fclean: clean
	${RM} ${NAME} ${BONUS_NAME}

re: all fclean

.PHONY = all bonus clean fclean re
