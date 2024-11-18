/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:07:00 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/18 00:53:57 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar_statement(char c, pars_param_t pars)
{
	
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putchar_error(char c)
{
	return (write(2, &c, 1));
}