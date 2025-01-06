/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 23:11:18 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/14 10:30:31 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr(char *str)
{
	size_t	ct;

	ct = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[ct])
	{
		if (ft_putchar(str[ct]) == -1)
			return (-1);
		++ct;
	}
	return ((int)(ct));
}
