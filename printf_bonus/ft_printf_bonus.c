/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:08:05 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/10 17:01:33 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int	ft_printf(const char *spec, ...)
{
	va_list	arg;
	t_data	*data;
	int		size;

	va_start(arg, spec);
	data = lst_tostr(spec, arg);
	va_end(arg);
	ft_putstr(data->str);
	size = ft_strlen(data->str);
	size += data->countZerro;
	delt_data(data);
	return (size);
}