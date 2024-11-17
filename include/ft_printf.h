/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:35:26 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/17 04:53:05 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define	FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

#define RESET		"\x1b[0m"
#define RED			"\x1b[31m"
#define GREEN		"\x1b[32m"
#define YELLOW		"\x1b[33m"
#define BLUE		"\x1b[34m"
#define MAGENTA		"\x1b[35m"
#define CYAN		"\x1b[36m"
#define TWINKLE		"\x1b[07m]"

typedef	struct	pars_param_s
{
	bool	check;
	size_t	number;
	size_t	point;
	bool	zero;
	bool	htag;
	bool	less;
	bool	more;
	bool	blank;
	bool	debug;
	char	effect;
	char	flag;
}			pars_param_t;

pars_param_t	ft_set_false_struct(pars_param_t pars);
pars_param_t	ft_set_struct(pars_param_t pars, char c);
pars_param_t	ft_load_param(pars_param_t pars, char *str);
size_t	ft_strlen(char *str);
size_t	ft_atoi(char const *str);
size_t	ft_count_atoi(int n);
int	ft_printf(char const *str, ...);
int	ft_select_params(va_list va, char *str);
int	ft_putstr(char *str);
int	ft_putstr_error(char *str);
int	ft_putchar(char c);
int	ft_putchar_error(char c);
bool	ft_check_char(char c);
void	ft_putnbr(int nb);
void	ft_putnbr_unsigned(unsigned int nb);
void	ft_putnbr_base(int nbr, char *base);
void	ft_print_addr(unsigned long adr, char *base)

#endif

//Flag
//	c
//	s
//	d
//	p
//	i
//	u
//	x
//	X
//	%

//Attribut
//	.
//	#
// ' '
//	+
//	-
//	0
//	D (Debug stdout)
//	C (Cyan)
//	B (Blue)
//	M (Magenta)
//	G (Green)
//	T (Twinkle)
//	Y (Yellow)