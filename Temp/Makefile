# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 19:51:33 by ticasali          #+#    #+#              #
#    Updated: 2024/12/08 13:07:35 by ticasali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libftprintf.a

DIR_SRCS =			src

SRCS =				$(DIR_SRCS)/ft_printf.c 	\
					$(DIR_SRCS)/ft_param.c		\
					$(DIR_SRCS)/ft_lenght.c		\
					$(DIR_SRCS)/ft_putchar.c	\
					$(DIR_SRCS)/ft_putstr.c		\
					$(DIR_SRCS)/ft_putnbr.c		\

DIR_OBJS =			.objs
OBJS =				$(SRCS:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)

CFLAGS =			-Wall -Wextra -Werror
AR = ar -rcs

all:				$(NAME)

$(DIR_OBJS)/%.o:	$(DIR_SRCS)/%.c $(INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@ -I./include

$(NAME):			$(OBJS) include/ft_printf.h
					$(AR) $(NAME) $(OBJS)

clean:
					$(RM) -r $(DIR_OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean
					$(MAKE) all

.PHONY:				all clean fclean re