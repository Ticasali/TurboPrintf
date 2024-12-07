/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:14:26 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/03 11:02:03 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include "stdio.h"

int		main(void)
{
	int val;
	char a = 'a';
	char str[] = "Bonjour";
	char str2[] = "vous";
	int d = -671;
	val = ft_printf("%d %d %d %d\n", d, d, d, d);
	printf("%d\n", val);
	val = printf("%d %d %d %d\n", d, d, d, d);
	printf("%d\n", val);
}