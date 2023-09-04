# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thclarac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 11:39:16 by thclarac          #+#    #+#              #
#    Updated: 2023/08/31 11:39:17 by thclarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC	=	client

NAME	=	server

OBJ_DIR =	OBJ/

SRCS	=	server.c

SRCC	=	client.c

OBJS	=	$(SRCS:.c=.o)

OBJC	=	$(SRCC:.c=.o)

OBJ	=	$(addprefix $(OBJ_DIR), $(OBJS)) $(addprefix $(OBJ_DIR), $(OBJC))

RM	=	rm -f

CFLAGS	=	-Wall -Werror -Wextra

all     :       $(OBJ_DIR) $(NAME)
	
$(OBJ_DIR)%.o:	%.c
		gcc $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
		mkdir $(OBJ_DIR)


$(NAME)	:	make_lib $(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ_DIR)$(OBJS) libft/libft.a
		gcc $(CFLAGS) -o $(NAMEC) $(OBJ_DIR)$(OBJC) libft/libft.a

make_lib :
		@make -s -C libft/

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME) $(NAMEC)

re 	:	fclean $(NAME)
