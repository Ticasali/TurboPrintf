/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:44:47 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/17 21:12:35 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "limits.h"

int	ft_putnbr(int nb)
{
	if (nb == INT_MIN)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		ft_putnbr(nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (1);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	long int	cmp;

	cmp = (long int)(nbr);
	if (cmp < 0)
	{
		cmp *= -1;
		ft_putchar('-');
	}
	if (cmp >= ft_strlen(base))
		ft_putnbr_base(cmp / ft_strlen(base), base);
	ft_putchar(base[cmp % ft_strlen(base)]);
	return (1);
}