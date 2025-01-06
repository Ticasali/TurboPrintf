/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:35:26 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/16 02:05:19 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>

# define RESET			"\x1b[0m"
# define TWINKLE		"\x1b[7m"
# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define MAGENTA		"\x1b[35m"
# define CYAN			"\x1b[36m"
# define MIN_BASE_16	"0123456789abcdef"
# define MAJ_BASE_16	"0123456789ABCDEF"
# define BASE_8			"01234567"
# define BASE_2			"01"

typedef	struct	pars_param_s
{
	char	carac[2];
	bool	error;
	bool	check;
	size_t	number;
	size_t	point;
	bool	point_s;
	bool	zero;
	bool	htag;
	bool	less;
	bool	more;
	bool	blank;
	char	effect;
	char	flag;
	short	debug;
}			pars_param_t;

pars_param_t	ft_set_false_struct(void);
pars_param_t	ft_set_struct(pars_param_t pars, char c);
pars_param_t	ft_load_param(char *str);
int	ft_strlen(char *str);
int	ft_atoi(char const *str);
int	ft_count_atoi(int n);
int	ft_count_atoui(unsigned int n);
size_t	count_len_precision(char *str, pars_param_t pars);
int	ft_printf(char const *str, ...);
int	ft_select_params(va_list va, char *str);
int	ft_putstr(char *str, pars_param_t pars);
int	ft_print_char(char c, short debug, char effect);
int	ft_putnbr(int nb, pars_param_t pars);
int	ft_putnbr_unsigned(unsigned int nb, pars_param_t pars);
int	ft_putnbr_base(int nbr, char *base, pars_param_t pars);
int	ft_print_adr(void *addr, short debug, char affect, char *base);
int	ft_print_color(char c, short debug);
int	ft_color_reset(short debug);
int	ft_putchar_statement(char c, pars_param_t pars);
int	ft_putstr_statement(char *str, pars_param_t pars);
int	ft_putnbr_statement(int num, pars_param_t pars);
int	ft_putnbr_unsigned_statement(unsigned int num, pars_param_t pars);
int	ft_putadrr_statement(void *adrr, pars_param_t pars, char *base);
int	ft_putnbr_base_statement(int num, pars_param_t pars, char *base);
int	ft_putnbr_prefix(int nb, pars_param_t pars);
int	ft_putadrr_error(short debug, char effect);
int	ft_putstr_error(pars_param_t pars);
bool	ft_check_char(char c);
bool	ft_check_flag(char c);
int	ft_putchar(char c);

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
//	o
//	b
//	f
//	F

//Attribut
//	.
//	#
// ' '
//	+
//	-
//	0
//	D (Debug stdout)
//	R (Red)
//	C (Cyan)
//	B (Blue)
//	M (Magenta)
//	G (Green)
//	T (Twinkle)
//	Y (Yellow)