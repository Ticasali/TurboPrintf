/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:37:45 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/14 10:31:52 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_strlen(char *str)
{
	int	ct;

	ct = 0;
	while (str[ct])
		++ct;
	return (ct);
}

int	ft_uint_lenght(unsigned int n)
{
	int	ret;

	ret = 0;
	if (ft_putnbr_unsigned(n) == -1)
		return (-1);
	while (n >= 10)
	{
		++ret;
		n /= 10;
	}
	return (ret + 1);
}

int	ft_int_lenght(int n)
{
	int	ret;

	ret = 0;
	if (ft_putnbr(n) == -1)
		return (-1);
	if (n < 0)
	{
		++ret;
		n *= -1;
	}
	while (n >= 10)
	{
		++ret;
		n /= 10;
	}
	return (ret + 1);
}

int	ft_base_lenght(int n, char *base)
{
	int				ret;
	unsigned int	cast;

	ret = 0;
	cast = (unsigned int)(n);
	if (ft_putnbr_base(n, base) == -1)
		return (-1);
	while (cast >= 16)
	{
		cast /= 16;
		++ret;
	}
	return (ret + 1);
}
