/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:21:43 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/14 10:28:23 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdbool.h>
# include <stddef.h>
# include <stdarg.h>

# define MIN_BASE_16 "0123456789abcdef"
# define MAJ_BASE_16 "0123456789ABCDEF"

int	ft_printf(char const *str, ...) __attribute__ ((format (printf, 1, 2)));
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

#endif