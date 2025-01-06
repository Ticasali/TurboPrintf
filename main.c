/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:09:07 by ticasali          #+#    #+#             */
/*   Updated: 2024/12/16 04:46:35 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/include/ft_printf_bonus.h"
#include "stdio.h"
#include "limits.h"

int	main(void)
{
	int ret;
	int	ret2;
	char str[] = "Test";
	char *str2 = NULL;
	int t = 2648;
	ret = ft_printf("   %YDs    \n", str);
	ret2 = printf("   %s    \n", str);
	printf("%d\n", ret);
	printf("%d\n", ret2);
}