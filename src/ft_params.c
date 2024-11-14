/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:57:24 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/14 17:47:25 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_select_params(va_list va, char *str)
{
	int	ret;

	ret = 0;
	if (str[0] == 'c')
		ret += ft_putchar(va_arg(va, int));
	else if (str[0] == 's')
		ret += ft_putstr(va_arg(va, char *));
	else if (str[0] == '%')
		ret += ft_putchar(va_arg(va, int));
	return (ret);
}