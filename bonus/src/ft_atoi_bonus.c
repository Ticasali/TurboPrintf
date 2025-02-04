/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:18:50 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/16 02:09:51 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	ft_atoi(char const *str)
{
	int	ret;
	size_t	ct;

	ct = 0;
	ret = 0;
	while (str[ct] >= '0' && str[ct] <= '9')
	{
		ret += (str[ct] - 48);
		++ct;
		if (str[ct] >= '0' && str[ct] <= '9')
			ret *= 10;
	}
	return (ret);
}

int	ft_count_atoi(int n)
{
	int	ret;

	ret = 0;
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

int	ft_count_atoui(unsigned int n)
{
	int	ret;

	ret = 0;
	while (n >= 10)
	{
		++ret;
		n /= 10;
	}
	return (ret + 1);
}