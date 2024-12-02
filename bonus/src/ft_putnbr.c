/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:44:47 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/30 07:57:02 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "limits.h"

int	ft_putnbr_prefix(int nb, pars_param_t pars)
{
	size_t	ct = 0;
	size_t	numb = ft_count_atoi(nb);
	if (pars.more == true)
		ft_print_char('+', pars.debug, pars.effect);
	if (pars.point > ft_count_atoi(nb))
	{
		while (ct <= (pars.point - numb))
		{
			ft_print_char('0', pars.debug, pars.effect);
			++ct;
		}
	}
	else if (pars.blank == true)
		ft_print_char(' ', pars.debug, pars.effect);
	if (ft_putnbr(nb, pars) == -1)
		return (-1);
	return (ft_count_atoi(nb));
}

int	ft_putnbr(int nb, pars_param_t pars)
{
	if (nb == INT_MIN)
	{
		if ((ft_print_char('-', pars.debug, pars.effect) == -1) 
			|| (ft_print_char('2', pars.debug, pars.effect) == -1))
			return (-1);
		ft_putnbr(147483648, pars);
	}
	else if (nb < 0)
	{
		if (ft_print_char('-', pars.debug, pars.effect) == -1)
			return (-1);
		ft_putnbr(nb * -1, pars);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10, pars);
		ft_putnbr(nb % 10, pars);
	}
	else
		if (ft_print_char(nb + 48, pars.debug, pars.effect) == -1)
			return (-1);
	return (1);
}

int	ft_putnbr_unsigned(unsigned int nb, pars_param_t pars)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10, pars);
		ft_putnbr_unsigned(nb % 10, pars);
	}
	else
		if (ft_print_char(nb + 48, pars.debug, pars.effect) == -1)
			return (-1);
	return (1);
}

int	ft_putnbr_base(int nbr, char *base, pars_param_t pars)
{
	long int	cmp;

	cmp = (long int)(nbr);
	if (cmp < 0)
	{
		cmp *= -1;
		if (ft_print_char('-', pars.debug, pars.effect) == -1)
			return (-1);
	}
	if (cmp >= (long int)ft_strlen(base))
		ft_putnbr_base(cmp / ft_strlen(base), base, pars);
	if (ft_print_char(base[cmp % ft_strlen(base)], pars.debug, pars.effect) == -1)
		return (-1);
	return (1);
}