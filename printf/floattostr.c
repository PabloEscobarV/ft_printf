/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floattostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:49:25 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/10 17:48:23 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdlib.h>
#include <limits.h>

char	*p_float(double n, const char *base, char *str, double count)
{
	static int	t = 1;
	int			size;

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
		t = 1;
		return (str);
	}
	*str = base[(long)n % size];
	p_float(n - (int)n, base, str + 1, count - 1);
	return (str);
}

char	*float_tostr_base(double n, const char *base, t_ui maxn)
{
	char	*num_int;
	char	*num_float;

	num_int = int_tostr_base((long)n, base);
	if (!num_int)
		return (NULL);
	if (maxn < 1)
		return (num_int);
	num_float = ft_calloc(maxn, sizeof(char));
	if (!num_float)
		return (NULL);
	ft_memset(num_float, SPEC[ZERO], maxn);
	p_float(n - (long)n, base, num_float, maxn);
	return (strjoinfree(num_int, num_float, 2));
}

t_data	*float_tostr(double n, const char *spec, const char *base, t_ui m)
{
	t_data	*num;

	num = t_datacrt(float_tostr_base(n, base, m), 0);
	if (!num)
		return (NULL);
	return (num);
}