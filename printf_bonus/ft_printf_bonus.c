/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:08:05 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/20 18:06:09 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

char	*ft_sprintf(const char *str, ...)
{
	va_list	arg;
	t_data	*data;
	char	*tmp;

	va_start(arg, str);
	data = lst_tostr(str, arg);
	va_end(arg);
	if (!data)
		return (ft_strdup(ERROR_BDA));
	tmp = ft_strdup(data->str);
	delt_data(data);
	return (tmp);
}

int	ft_printf(const char *spec, ...)
{
	va_list	arg;
	int		size;

	va_start(arg, spec);
	size = printdata(spec, arg);
	va_end(arg);
	return (size);
}
