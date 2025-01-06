/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:11:01 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/14 10:30:23 by ticasali         ###   ########.fr       */
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
	else if (str[0] == 'd')
		ret += ft_int_lenght(va_arg(va, int));
	else if (str[0] == 'p')
		ret += ft_print_adr(va_arg(va, void *), MIN_BASE_16);
	else if (str[0] == 'i')
		ret += ft_int_lenght(va_arg(va, int));
	else if (str[0] == 'u')
		ret += ft_uint_lenght(va_arg(va, unsigned int));
	else if (str[0] == 'x')
		ret += ft_base_lenght(va_arg(va, int), MIN_BASE_16);
	else if (str[0] == 'X')
		ret += ft_base_lenght(va_arg(va, int), MAJ_BASE_16);
	else if (str[0] == '%')
		ret += ft_putchar('%');
	return (ret);
}
