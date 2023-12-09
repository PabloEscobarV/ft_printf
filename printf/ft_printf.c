/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:08:05 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/07 15:54:07 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int	ft_printf(const char *spec, ...)
{
	va_list	arg;
	char	*str;
	int		size;

	va_start(arg, spec);
	str = lst_tostr(spec, arg);
	va_end(arg);
	ft_putstr(str);
	size = ft_strlen(str);
	free(str);
	return (size);
}

// int main (void)
// {
// 	int 	size_p;
// 	int 	size_f;
// 	char 	s2[] = "abcd efgh 67580 78";
// 	size_p = 0;
// 	size_f = 0;
	
// 	size_p += printf("| %% |\n");
// 	size_f += ft_printf("| %% |\n");
	
// 	size_p += printf("| %%%% |\n");
// 	size_f += ft_printf("| %%%% |\n");

// 	size_p += printf("| %% %% %% |\n");
// 	size_f += ft_printf("| %% %% %% |\n");

// 	size_p += printf("| %%  %%  %% |\n");
// 	size_f += ft_printf("| %%  %%  %% |\n");

// 	size_p += printf("|%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%|\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// 	size_f += ft_printf("|%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%|\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	
// 	size_p += printf("| %p %p |\n", ULONG_MAX, -ULONG_MAX);
// 	size_f += ft_printf("| %p %p |\n", ULONG_MAX, -ULONG_MAX);
	
// 	return (0);
// }