/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:07:00 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/15 12:36:12 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	ft_print_char(char c, short debug, char effect)
{
	if (effect == '\0')
		return (write(debug, &c, 1));
	if (ft_print_color(effect, debug) == -1)
		return (-1);
	if (write(debug , &c, 1) == -1)
		return (-1);
	if (ft_color_reset(debug) == -1)
		return (-1);
	return (1);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}