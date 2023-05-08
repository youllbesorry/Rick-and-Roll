# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 00:50:04 by bfaure            #+#    #+#              #
#    Updated: 2023/04/29 00:50:04 by bfaure           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = Mouse_pos

SRCS =	mouse_pos.c\

DIR_SRCS = src/

DIR_OBJS = .objs/

#DIR_HEAD = headers/

OBJS = ${SRCS:%.c=${DIR_OBJS}%.o}

CC = cc

MKDIR = mkdir -p

#HEADERS	= 	

CFLAGS	= -Wall -Wextra -Werror -g3

all :		${NAME}

clean :
			rm -rf ${DIR_OBJS}

fclean :	clean
			rm -rf ${NAME}

re :		fclean
			$(MAKE) all

${DIR_OBJS}%.o: 	${DIR_SRCS}%.c | ${DIR_OBJS}
					${CC} ${CFLAGS} -I -lSDL -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

${NAME} :	${OBJS}
			ar -rc ${NAME} ${OBJS}

.PHONY:		all clean fclean re