/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:21:43 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/02 22:30:30 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdbool.h>
#include <stddef.h>
#include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_strlen(char *str);
int	ft_select_params(va_list va, char *str);
int	ft_uint_lenght(unsigned int n);
int	ft_int_lenght(int n);
int	ft_putchar(char c);
int	ft_print_adr(void	*adrr, char *base);
int	ft_putnbr_base(int nbr, char *base);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_base_lenght(int n, char *base);
bool	ft_check_flag(char c);

#endif