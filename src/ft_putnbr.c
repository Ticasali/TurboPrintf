/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:35:30 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/14 10:31:36 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "limits.h"

int	ft_putnbr(int nb)
{
	if (nb == INT_MIN)
	{
		if ((ft_putchar('-') == -1)
			|| (ft_putchar('2' == -1)))
			return (-1);
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		ft_putnbr(nb * -1);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		if (ft_putchar(nb + 48) == -1)
			return (-1);
	return (0);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10);
		ft_putnbr_unsigned(nb % 10);
	}
	else
		if (ft_putchar(nb + 48) == -1)
			return (-1);
	return (0);
}

int	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	cmp;

	cmp = (unsigned int)(nbr);
	if (cmp >= (unsigned int)ft_strlen(base))
		ft_putnbr_base(cmp / ft_strlen(base), base);
	if (ft_putchar(base[cmp % ft_strlen(base)]) == -1)
		return (-1);
	return (0);
}

int	ft_print_adr(void	*adrr, char *base)
{
	char			stock[12];
	int				cmp;
	unsigned long	adr;

	if (adrr == NULL)
		return (ft_putstr("(nil)"));
	cmp = -1;
	adr = (unsigned long)(adrr);
	while (++cmp < 12)
	{
		stock[cmp] = base[adr % 16];
		adr = adr / 16;
	}
	if (ft_putchar('0') == -1
		|| ft_putchar('x') == -1)
		return (-1);
	while (cmp--)
	{
		if (ft_putchar(stock[cmp]) == -1)
			return (-1);
	}
	return (14);
}
