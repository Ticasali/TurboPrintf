/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:31:32 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/30 08:10:44 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_adr(void	*adrr, short debug ,char effect, char *base)
{
	char	stock[12];
	int		cmp;
	unsigned long adr;
	cmp = -1;
	adr = (unsigned long)(unsigned char *)(adrr);
	while (++cmp < 12)
	{
		stock[cmp] = base[adr % 16];
		adr = adr / 16;
	}
	if (ft_print_char('0', debug, effect) == -1
		|| ft_print_char('x', debug, effect) == -1)
			return (-1);
	while (cmp--)
	{
		if (ft_print_char(stock[cmp], debug, effect) == -1)
			return (-1);
	}
	return (14);
}