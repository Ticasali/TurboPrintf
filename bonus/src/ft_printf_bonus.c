/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:36:44 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/16 03:24:23 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	ft_printf(char const *str, ...)
{
	va_list	va;
	size_t	ct;
	int		ret;
	int		temp;

	ct = 0;
	ret = 0;
	if (!str)
		return (-1);
	va_start(va, str);
	while (str[ct] != '\0')
	{
		if (str[ct] != '%')
		{
			if (ft_putchar(str[ct]) == -1)
				return (-1);
			++ret;
		}
		temp = 0;
		if (str[ct] == '%')
			temp = ft_select_params(va, (char *)(&str[++ct]));
		if (temp == -1)
			return (-1);
		while (temp != 0 && ft_check_flag(str[ct]) == false)
			++ct;
		ret += temp;
		++ct;
	}
	va_end(va);
	return (ret);
}
