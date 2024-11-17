/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:14:32 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/16 18:10:27 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	ft_putstr_error(char *str)
{
	return (write(1, str, ft_strlen(str)));
}
