# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 18:45:57 by ael-hamd          #+#    #+#              #
#    Updated: 2022/10/03 01:16:25 by aklaikel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 	cub3d
SRCS			=	cub3d.c \
					./Parsing/cub3d_parse_tools.c \
					./Parsing/cub3d_parse.c \
					./Parsing/cub3d_parse2.c \
					./Parsing/cub3d_parse3.c \
					./Parsing/cub3d_parse4.c \
					./Parsing/cub3d_parse_tools2.c \
					./Parsing/cub3d_pase_map.c \
					./Parsing/cub3d_pase_map2.c \
					./srcs/raycub3d.c \
					./srcs/key_listener.c \
					./srcs/directions.c \
					./srcs/minimap.c \
					./srcs/vectorfun.c \
					./srcs/dda_algorithm.c \
					./srcs/color_init.c \
					./srcs/load_imgs.c  \
					./srcs/drawtoscreen.c \
					./srcs/raycast.c 
					
OBJS			=	$(SRCS:.c=.o)

CC				= 	cc
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror
MLXFLAGS		= 	-lmlx -framework OpenGL -framework AppKit
HEADER			= 	include/cub3d.h


all:				${NAME}	

${NAME}:  			$(MLX) $(OBJS) 
					$(CC) ${CFLAGS} ${OBJS}  $(MLXFLAGS) -o $@
	
%.o:				%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

clean:				
					$(RM) $(OBJS) $(BOBJS)

fclean:				clean
					$(RM) ${NAME}

.PHONY:				all clean fclean re