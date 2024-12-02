/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:14:32 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/29 12:10:37 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	count_len_precision(char *str, pars_param_t pars)
{
	size_t	ct;

	ct = 0;
	if (pars.point_s == false)
		return ((int)ft_strlen(str));
	while (str[ct] != '\0' && ct < pars.point)
		++ct;
	return (ct);
}

int	ft_putstr(char *str, pars_param_t pars)
{
	size_t	ct;

	ct = 0;
	if (pars.point_s == true)
	{
		while (str[ct] != '\0' && ct < pars.point)
		{
			if (ft_print_char(str[ct], pars.debug, pars.effect) == -1)
				return (-1);
			++ct;
		}
	}
	else
	{
		while (str[ct] != '\0')
		{
			if (ft_print_char(str[ct], pars.debug, pars.effect) == -1)
				return (-1);
			++ct;
		}
	}
	return ((int)(count_len_precision(str, pars)));
}