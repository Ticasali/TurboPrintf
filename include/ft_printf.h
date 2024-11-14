/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:35:26 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/14 17:47:28 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define	FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

size_t	ft_strlen(char *str);
int	ft_printf(char const *str, ...);
int	ft_select_params(va_list va, char *str);
int	ft_putstr(char *str);
int	ft_putchar(char c);

#endif