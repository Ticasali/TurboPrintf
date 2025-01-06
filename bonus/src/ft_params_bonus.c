/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:57:24 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/16 04:46:08 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

bool	ft_check_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'p' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X')
		return (true);
	return (false);
}

bool	ft_check_char(char c)
{
	if ((c == 'c' || c == 's' || c == 'd' || c == 'p' || c == 'i' 
		|| c == 'u' || c == 'x' || c == 'X' || c == '.' || c == 'R'
		|| c == '#' || c == ' ' || c == '+' || c == '-'
		|| c == '0' || c == 'D' || c == 'C' || c == 'B'
		|| c == 'M' || c == 'G' || c == 'T' || c == 'Y') || (c >= '1' && c <= '9'))
		return (true);
	return (false);
}

bool	ft_check_attribut(char c)
{
	if (c == '#' || c == ' ' || c == '+' || c == '-' || c == 'R' || c == '.'
		|| c == '0' || c == 'D' || c == 'C' || c == 'B'
		|| c == 'M' || c == 'G' || c == 'T' || c == 'Y')
		return (true);
	return (false);
}

pars_param_t	ft_set_false_struct(void)
{
	pars_param_t pars;
	
	pars.carac[0] = ' ';
	pars.carac[1] = '0';
	pars.error = false;
	pars.check = false;
	pars.number = 0;
	pars.point = 0;
	pars.zero = false;
	pars.htag = false;
	pars.less = false;
	pars.more = false;
	pars.blank = false;
	pars.debug = 1;
	pars.point_s = false;
	pars.effect = '\0';
	pars.flag = '\0';
	return (pars);
}

pars_param_t	ft_set_struct(pars_param_t pars, char c)
{
	if (pars.number != 0 && (ft_check_attribut(c) == true))
		pars.error = true;
	else if ((c == 'C' || c == 'B' || c == 'M' || c == 'G' || c == 'T' || c == 'Y' || c == 'R')
		&& pars.effect == '\0')
		pars.effect = c;
	else if ((c == 'c' || c == 's' || c == 'd' || c == 'p' 
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' 
		|| c == 'e' || c == 'E' || c == 'f' || c == 'F') && pars.flag == '\0')
		pars.flag = c;
	else if (c == 'D')
		pars.debug = 2;
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
	{
		pars.error = true;
		write(1, "A", 1);
	}
	return (pars);
}

pars_param_t	ft_load_param(char *str)
{
	size_t	ct;
	pars_param_t pars;

	ct = 0;
	pars = ft_set_false_struct();
	while (ft_check_flag(str[ct]) != true && pars.error == false)
	{
		if (str[ct] == '.')
		{
			if (pars.point_s == false)
				pars.point_s = true;
			else
				pars.error = true;
			pars.point = ft_atoi(&str[ct + 1]);
			ct += (ft_count_atoi(pars.point));
		}
		else if (str[ct] >= '1' && str[ct] <= '9')
		{
			pars.number = ft_atoi(&str[ct]);
			ct += ft_count_atoi(pars.number) - 1;
		}
		else
			pars = ft_set_struct(pars, str[ct]);
		if (ft_check_char(str[ct]) == false)
			break;
		ct++;
	}
	pars = ft_set_struct(pars, str[ct]);
	return (pars);
}

int	ft_select_params(va_list va, char *str)
{
	int	ret;
	pars_param_t	pars;

	pars = ft_load_param(str);
	if (pars.flag == '\0' || pars.error == true || (pars.blank == true && pars.more == true)
		|| (pars.zero == true && pars.less == true))
		return (-1);
	ret = 0;
	if (pars.flag == 'c')
		ret += ft_putchar_statement(va_arg(va, int), pars);
	else if (pars.flag == 's')
		ret += ft_putstr_statement(va_arg(va, char *), pars);
	else if (pars.flag == 'd')
		ret += ft_putnbr_statement(va_arg(va, int), pars);
	else if (pars.flag == 'p')
		ret += ft_putadrr_statement(va_arg(va, void *), pars, "0123456789abcdef");
	else if (pars.flag == 'i')
		ret += ft_putnbr_statement(va_arg(va, int), pars);
	else if (pars.flag == 'u')
		ret += ft_putnbr_unsigned_statement(va_arg(va, unsigned int), pars);
	else if (pars.flag == 'x')
		ret += ft_putnbr_base_statement(va_arg(va, int), pars, "0123456789abcdef");
	else if (pars.flag == 'b')
		ret += ft_putnbr_base_statement(va_arg(va, int), pars, "01");
	else if (pars.flag == 'o')
		ret += ft_putnbr_base_statement(va_arg(va, int), pars, "01234567");
	else if (pars.flag == 'X')
		ret += ft_putnbr_base_statement(va_arg(va, int), pars, "0123456789ABCDEF");
//	else if (str[0] == '%')
//		ret += ft_putchar(va_arg(va, int));
	return (ret);
}