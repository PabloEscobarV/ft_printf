/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floattostr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:49:25 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/09 17:38:39 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

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
	t_mod	*mod;
	t_data	*num;
	char	*tmp;
	char	*num_orig;

	mod = setmod(spec, MOD, SPEC);
	if (!mod)
		return (NULL);
	if (mod->flags[PREC])
		m = mod->precision;
	num = t_datacrt(float_tostr_base(n, base, m), 0);
	if (!num)
		return (NULL);
	num_orig = num->str;
	setsign(mod, num);
	tmp = modnstr_crt(mod, num->str);
	if (!tmp)
		return (NULL);
	if (!ft_isdigit(*num_orig))
		swap_sign(mod, tmp, num->str, num_orig);
	if (mod->flags[INDENT] == MOD[INDENT])
		return (retres_fin(mod, num, num->str, tmp));
	return (retres_fin(mod, num, tmp, num->str));
}
