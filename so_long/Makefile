# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 18:38:51 by apiscopo          #+#    #+#              #
#    Updated: 2024/12/05 18:59:04 by apiscopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
LIBMLX = mlx/libmlx.a

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

SRCS =	$(wildcard src/*.c )

HEAD =	includes/so_long.h

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

CC = gcc
CF = -Wall -Werror -Wextra #-fsanitize=address -static-libasan
SL = -Imlx -Imlx_linux -lXext -lX11 -lm -lz
CI = -I ./src/


AR = ar rcs
RM = rm -rf

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

all: ${NAME}

# Binary creation

${NAME}: ${SRCS} ${HEAD} ${LIBFT} ${LIBMLX}
	${CC} ${CF} ${CI} ${SRCS} ${LIBFT} ${LIBMLX} ${SL} -o ${NAME}

${LIBMLX}:
	make -C mlx/

# Mandatory rules

clean:
	${RM} mlx/*.o mlx/test/*.o src/*.o

fclean: clean
	${RM} ${NAME}
	${RM} mlx/libmlx_Linux.a
	make clean -C mlx

re: fclean all
