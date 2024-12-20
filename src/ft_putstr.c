/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 23:11:18 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/02 15:58:38 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr(char *str)
{
	int	ct;

	ct = 0;
	while (str[ct])
	{
		if (ft_putchar(str[ct]) == -1)
			return (-1);
		++ct;
	}
	return (ct);
}