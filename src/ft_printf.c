/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:36:44 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/14 17:42:20 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	va;
	size_t	ct;
	int		ret;

	ct = 0;
	ret = 0;
	va_start(va, str);
	while (str[ct] != '\0')
	{
		if (str[ct] == '%')
			ret = ft_select_params(va, (char *)(&str[ct + 1]));
		else if (str[ct - 1] != '%')
			ft_putchar(str[ct]);
		++ct;
	}
	va_end(va);
	return (ret);
}

int	main(int ac, char **av)
{
	char c = 'R';
	char str[] = "Bonjour";
	ft_printf("%s%c\n\n", str, c);
}