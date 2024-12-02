# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 19:51:33 by ticasali          #+#    #+#              #
#    Updated: 2024/12/02 17:12:47 by ticasali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libftprintf.a

DIR_SRCS =			src
DIR_BONUS=			bonus/src

SRCS =				$(DIR_SRCS)/ft_printf.c 	\
					$(DIR_SRCS)/ft_param.c		\
					$(DIR_SRCS)/ft_lenght.c		\
					$(DIR_SRCS)/ft_putchar.c	\
					$(DIR_SRCS)/ft_putstr.c		\
					$(DIR_SRCS)/ft_putnbr.c		\

SRCS_BONUS =		$(DIR_BONUS)/ft_printf.c	\
					$(DIR_BONUS)/ft_atoi.c		\
					$(DIR_BONUS)/ft_params.c	\
					$(DIR_BONUS)/ft_putadrr.c	\
					$(DIR_BONUS)/ft_putchar.c	\
					$(DIR_BONUS)/ft_putnbr.c	\
					$(DIR_BONUS)/ft_putstr.c	\
					$(DIR_BONUS)/ft_statement.c	\
					$(DIR_BONUS)/ft_strlen.c	\

DIR_OBJS =			.objs
DIR_OBJS_BONUS =			.objs_bonus
OBJS =				$(SRCS:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)
OBJS_BONUS =		$(SRCS_BONUS:$(DIR_BONUS)/%.c=$(DIR_OBJS_BONUS)/%.o)

CFLAGS =			-Wall -Wextra -Werror
AR = ar -rcs

all:				$(NAME)

$(DIR_OBJS)/%.o:	$(DIR_SRCS)/%.c $(INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@ -I./include

$(DIR_OBJS_BONUS)/%.o:	$(DIR_BONUS)/%.c $(INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@ -I./bonus/include

$(NAME):			$(OBJS) include/ft_printf.h
					$(AR) $(NAME) $(OBJS)

$(NAME)_bonus:		$(OBJS_BONUS) bonus/include/ft_printf.h
					$(AR) $(NAME) $(OBJS_BONUS)

clean:
					$(RM) -r $(DIR_OBJS) $(DIR_OBJS_BONUS)

fclean:				clean
					$(RM) $(NAME) $(NAME)_bonus

re:					fclean
					$(MAKE) all

bonus:
					$(MAKE) $(NAME)_bonus

.PHONY:				all clean fclean re bonus