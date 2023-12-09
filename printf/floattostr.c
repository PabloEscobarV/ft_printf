/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floattostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:49:25 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/07 15:47:48 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdlib.h>
#include <limits.h>

char	*p_float(double n, const char *base, char *str, double count)
{
	int			size;
	static int	t = 1;

	size = ft_strlen(base);
	n *= size;
	if (t)
	{
		*str = FDOT;
		++str;
		t = 0;
	}
	if (n - (long)n == 0 || count < 2)
	{
		*str = base[(int)n];
		*(str + 1) = '\0';
		return (str);
	}
	*str = base[(long)n % size];
	p_float(n - (int)n, base, str + 1, count - 1);
	return (str);
}

const char	*float_tostr_base(double n, const char *base, t_ui maxn)
{
	char	*num_int;
	char	*num_float;

	num_int = int_tostr_base((long)n, base);
	if (!num_int)
		return (ERROR_BDA);
	if (maxn < 1)
		return (num_int);
	num_float = ft_calloc(maxn, sizeof(char));
	if (!num_float)
		return (ERROR_BDA);
	ft_memset(num_float, SPEC[ZERO], maxn);
	p_float(n - (long)n, base, num_float, maxn);
	return (ft_strjoin_free(num_int, num_float, 2));
}

const char	*float_tostr(double n, const char *spec, const char *base, t_ui m)
{
	char	*tmp;

	tmp = (char *)spec;
	++tmp;
	--tmp;
	return (float_tostr_base(n, base, m));
}
