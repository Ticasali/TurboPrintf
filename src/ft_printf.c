/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:10:48 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/03 10:59:39 by ticasali         ###   ########.fr       */
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
			temp = ft_select_params(va, (char *)(&str[++ct]));
		if (temp == -1)
			return (-1);
		ret += temp;
		if (str[ct - 1] != '%' && str[ct] != '\0')
		{
			ret++;
			if (ft_putchar(str[ct]) == -1)
				return (-1);
		}
		++ct;
	}
	va_end(va);
	return (ret);
}