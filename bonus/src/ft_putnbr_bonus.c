/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:44:47 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/16 03:08:44 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "limits.h"

int	ft_putnbr_prefix(int nb, pars_param_t pars)
{
	int	ct = 0;
	int	ret = 0;
	int	numb = ft_count_atoi(nb);
	if (pars.more == true && nb >= 0)
	{
		if (ft_print_char('+', pars.debug, pars.effect) == -1)
			return (-1);
		++ret;
	}
	if (nb < 0 && pars.blank == false)
	{
		if (ft_print_char('-', pars.debug, pars.effect) == -1)
			return (-1);
		nb *= -1;
		++ret;
	}
	if ((int)pars.point > ft_count_atoi(nb))
	{
		while (ct <= ((int)pars.point - numb))
		{
			if (ft_print_char('0', pars.debug, pars.effect) == -1)
				return (-1);
			++ct;
			++ret;
		}
	}
	else if (pars.blank == true)
	{
		if (ft_print_char(' ', pars.debug, pars.effect) == -1)
			return (-1);
		++ret;
	}
	if (ft_putnbr(nb, pars) == -1)
		return (-1);
	return (ret + ft_count_atoi(nb));
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
	unsigned int	cmp;

	cmp = (unsigned int)(nbr);
	if (cmp < 0)
	{
		cmp *= -1;
		if (ft_print_char('-', pars.debug, pars.effect) == -1)
			return (-1);
	}
	if (cmp >= (unsigned int)ft_strlen(base))
		ft_putnbr_base(cmp / ft_strlen(base), base, pars);
	if (ft_print_char(base[cmp % ft_strlen(base)], pars.debug, pars.effect) == -1)
		return (-1);
	return (1);
}