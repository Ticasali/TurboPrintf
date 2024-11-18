/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:57:24 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/18 03:26:35 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

bool	ft_check_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'p' || c == 'i' 
		|| c == 'u' || c == 'x' || c == 'X')
		return (true);
	return (false);
}

bool	ft_check_char(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'p' || c == 'i' 
		|| c == 'u' || c == 'x' || c == 'X' || c == '.'
		|| c == '#' || c == ' ' || c == '+' || c == '-'
		|| c == '0' || c == 'D' || c == 'C' || c == 'B'
		|| c == 'M' || c == 'G' || c == 'T' || c == 'Y')
		return (true);
	return (false);
}

pars_param_t	ft_set_false_struct(pars_param_t pars)
{
	pars.error = false;
	pars.check = false;
	pars.number = 0;
	pars.point = 0;
	pars.zero = false;
	pars.htag = false;
	pars.less = false;
	pars.more = false;
	pars.blank = false;
	pars.debug = false;
	pars.effect = '\0';
	pars.flag = '\0';
}

pars_param_t	ft_set_struct(pars_param_t pars, char c)
{
	if ((c == 'C' || c == 'B' || c == 'M' || c == 'G' || c == 'T' || c == 'Y')
		&& pars.number == '\0')
		pars.effect = c;
	else if ((c == 'c' || c == 's' || c == 'd' || c == 'p' 
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' 
		|| c == 'e' || c == 'E' || c == 'f' || c == 'F') && pars.flag == '\0')
		pars.flag = c;
	else if (c == 'D')
		pars.debug = true;
	else if (c == '#')
		pars.htag = true;
	else if (c == '-')
		pars.less = true;
	else if (c == '+')
		pars.more = true;
	else if (c == ' ')
		pars.blank = true;
	else if (c == '0')
		pars.zero = true;
	else
		pars.check = true;
	return (pars);
}

pars_param_t	ft_load_param(pars_param_t pars, char *str)
{
	size_t	ct;

	ct = 0;
	pars = ft_set_false_struct(pars);
	while (ft_check_char(str[ct]) == true && pars.check == false)
	{
		if (str[ct] == '.')
		{
			pars.point = ft_atoi(&str[ct]);
			ct += (ft_count_atoi(pars.point) + 1);
		}
		if (str[ct] >= '1' && str[ct] <= '9')
		{
			pars.number = ft_atoi(&str[ct]);
			ct += ft_count_atoi(pars.number);
		}
		pars = ft_set_struct(pars, str[ct]);
		ct++;
	}
	return (pars);
}

int	ft_select_params(va_list va, char *str)
{
	int	ret;
	pars_param_t	pars;

	pars = ft_load_param(pars, str);
	ret = 0;
	if (pars.flag == 'c')
	{
		ret += ft_putchar_statement(va_arg(va, int), pars);
	}
	else if (pars.flag == 's')
		ret += ft_putstr(va_arg(va, char *));
	else if (pars.flag == 'd')
		ret += ft_putnbr(va_arg(va, int));
	else if (pars.flag == 'p')
		ret += ft_print_addr(va_arg(va, void *), "0123456789abcdef");
	else if (pars.flag == 'i')
		ret += ft_putnbr(va_arg(va, int));
	else if (pars.flag == 'u')
		ret += ft_putnbr_unsigned(va_arg(va, unsigned int));
	else if (pars.flag == 'x')
		ret += ft_putnbr_base(va_arg(va, int),"0123456789abcdef");
	else if (pars.flag == 'X')
		ret += ft_putnbr_base(va_arg(va, int),"0123456789ABCDEF");
//	else if (str[0] == '%')
//		ret += ft_putchar(va_arg(va, int));
	return (ret);
}