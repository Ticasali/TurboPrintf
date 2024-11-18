/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:31:32 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/17 21:11:49 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_addr(void	*adrr, char *base)
{
	char	stock[16];
	int		cmp;
	unsigned long adr;
	cmp = -1;
	adr = (unsigned long)(unsigned char *)(adrr);
	while (++cmp < 16)
	{
		stock[cmp] = base[adr % 16];
		adr = adr / 16;
	}
	while (cmp--)
	{
		write(1, &stock[cmp], 1);
	}
	return (16);
}