/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:36:44 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/01 22:50:21 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	va;
	size_t	ct;
	int		ret;
	int		temp;

	ct = 0;
	ret = 0;
	va_start(va, str);
	while (str[ct] != '\0')
	{
		temp = 0;
		if (str[ct] == '%')
			temp = ft_select_params(va, (char *)(&str[ct + 1]));
		if (temp == -1)
			return (-1);
		while (temp != 0 && ft_check_flag(str[ct]) == false)
			++ct;
		ret += temp;
		if (ft_check_flag(str[ct]) == true)
			++ct;
		if (str[ct] != '%' && str[ct] != '\0')
			if (ft_putchar(str[ct]) == -1)
				return (-1);
		if (str[ct] != '\0')
			++ct;
	}
	va_end(va);
	return (ret);
}