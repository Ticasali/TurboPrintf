/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_statement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:07:27 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/01 17:51:04 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_color(char c, short debug)
{
	if (c == 'T')
		return (write(debug, TWINKLE, 5));
	if (c == 'R')
		return (write(debug, RED, 5));
	if (c == 'G')
		return (write(debug, GREEN, 5));
	if (c == 'Y')
		return (write(debug, YELLOW, 5));
	if (c == 'C')
		return (write(debug, CYAN, 5));
	if (c == 'B')
		return (write(debug, BLUE, 5));
	if (c == 'M')
		return (write(debug, MAGENTA, 5));
	return (0);
}

int	ft_color_reset(short debug)
{
	return (write(debug, RESET, 4));
}

int	ft_putchar_statement(char c, pars_param_t pars)
{
	size_t	ct;

	ct = 0;
	if (pars.htag == true || pars.blank == true || pars.more == true || pars.zero == true || pars.point != 0)
		return (-1);
	if (pars.number != 0)
	{
		if (pars.less == true)
			if (ft_print_char(c, pars.debug, pars.effect) == -1)
				return (-1);
		while (++ct < pars.number)
			if (ft_print_char(' ', pars.debug, pars.effect) == -1)
				return (-1);
		if (pars.less == false)
			if (ft_print_char(c, pars.debug, pars.effect) == -1)
				return (-1);
		return (pars.number);
	}
	else
		if (ft_print_char(c, pars.debug, pars.effect) == -1)
			return (-1);
	return (1);
}

int	ft_putstr_statement(char *str, pars_param_t pars)
{
	size_t	ct;
	size_t	res;

	ct = 0;
	res = count_len_precision(str, pars);
	if (pars.htag == true || pars.blank == true || pars.more == true || pars.zero == true)
		return (-1);
	if (pars.number != 0)
	{
		if (pars.less == true)
			if (ft_putstr(str, pars) == -1)
				return (-1);
		while (++ct < (pars.number - res + 1))
			if (ft_print_char(' ', pars.debug, pars.effect) == -1)
				return (-1);
		if (pars.less == false)
			if (ft_putstr(str, pars) == -1)
				return (-1);
	}
	else
		if (ft_putstr(str, pars) == -1)
			return (-1);
	return (ct + res);
}

int	ft_putnbr_statement(int num, pars_param_t pars)
{
	size_t	ct;

	ct = 0;
	if (pars.htag == true)
		return (-1);
	if (pars.number != 0)
	{
		if (pars.less == true)
			if (ft_putnbr_prefix(num, pars) == -1)
				return (-1);
		while (++ct < (pars.number - ft_count_atoui(num)))
			if (ft_print_char(pars.carac[pars.zero], pars.debug, pars.effect) == -1)
				return (-1);
		if (pars.less == false)
			if (ft_putnbr_prefix(num, pars) == -1)
				return (-1);
		return (ct + ft_count_atoui(num));
	}
	else
		if (ft_putnbr_prefix(num, pars) == -1)
			return (-1);
	return (1);
}

int	ft_putnbr_unsigned_statement(unsigned int num, pars_param_t pars)
{
	size_t	ct;

	ct = 0;
	if (pars.htag == true || pars.blank == true || pars.more == true)
		return (-1);
	if (pars.number != 0)
	{
		if (pars.less == true)
			if (ft_putnbr_unsigned(num, pars) == -1)
				return (-1);
		while (++ct < (pars.number - ft_count_atoui(num)))
			if (ft_print_char(pars.carac[pars.zero], pars.debug, pars.effect) == -1)
				return (-1);
		if (pars.less == false)
			if (ft_putnbr_unsigned(num, pars) == -1)
				return (-1);
		return (ct + ft_count_atoui(num));
	}
	else
		if (ft_putnbr_unsigned(num, pars) == -1)
			return (-1);
	return (1);
}

int	ft_putadrr_statement(void *adrr, pars_param_t pars, char *base)
{
	size_t	ct;

	ct = 0;
	if (pars.htag == true || pars.blank == true || pars.more == true || pars.zero == true)
		return (-1);
	if (pars.number != 0)
	{
		if (pars.less == true)
			if (ft_print_adr(adrr, pars.debug, pars.effect, base) == -1)
				return (-1);
		while (++ct < (pars.number - 16))
			if (ft_print_char(' ', pars.debug, pars.effect) == -1)
				return (-1);
		if (pars.less == false)
			if (ft_print_adr(adrr, pars.debug, pars.effect, base) == -1)
				return (-1);
		return (ct + 16);
	}
	else
		if (ft_print_adr(adrr, pars.debug, pars.effect, base) == -1)
			return (-1);
	return (1);
}

int	ft_putnbr_base_statement(int num, pars_param_t pars, char *base)
{
	size_t	ct;

	ct = 0;
	if (pars.blank == true || pars.more == true)
		return (-1);
	if (pars.number != 0)
	{
		if (pars.less == true)
			if (ft_putnbr_base(num, base, pars) == -1)
				return (-1);
		while (++ct < (pars.number - ft_count_atoi(num)))
			if (ft_print_char(pars.carac[pars.zero], pars.debug, pars.effect) == -1)
				return (-1);
		if (pars.less == false)
			if (ft_putnbr_base(num, base, pars) == -1)
				return (-1);
		return (ct + ft_count_atoi(num));
	}
	else
		if (ft_putnbr_base(num, base, pars) == -1)
			return (-1);
	return (1);
}
