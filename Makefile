# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 21:12:24 by jkimmina          #+#    #+#              #
#    Updated: 2018/06/14 19:26:04 by jkimmina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC =	main.c		\
		init.c		\
		obj_math.c	\
		vec_math.c	\
		ray.c		\
		draw.c

OBJ = $(SRC:.c=.o)

HEADER = rtv1.h		\
		 structs.h	\
		 init.h		\
		 obj_math.h	\
		 vec_math.h	\
		 ray.h		\
		 draw.h

HEADERDIR = ./inc	\

FLAGS = -Wall -Werror -Wextra

#LIBFT = ./libft/libft.a
#LIBFTLINK = -L./libft/ -lft

LIBMLX = ./minilibx/libmlx.a
LIBMLXLINK = -L./minilibx/ -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

libft: $(LIBFT)

$(OBJ): src/*.c
	gcc $(FLAGS) -c $(addprefix src/, $(SRC)) -I$(HEADERDIR) 

$(LIBFT):
	make -C ./libft

libmlx: $(LIBMLX)

$(LIBMLX): 
	make -C ./minilibx/

$(NAME): $(LIBMLX) $(OBJ)
	@#$(LIBFT)
	gcc $(OBJ) -o $(NAME) $(LIBMLXLINK)
	@#$(LIBFTLINK)

clean:
	/bin/rm -f $(OBJ) $(HEADER:.h=.h.gch)

fclean: clean
	/bin/rm -f $(NAME)
	#make fclean -C libft/
	make clean -C minilibx/

re: fclean all
