/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:41:52 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/07 15:48:11 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdlib.h>
#include <limits.h>

char	*int_tostr_base(long n, const char *base)
{
	char	*str;
	t_ui	base_s;
	t_ul	tmp;

	str = crtnumstr(n, base);
	if (!str)
		return ((char *)error(ERROR_BDA));
	base_s = ft_strlen(base);
	if (n < 0)
	{
		if (n == LONG_MIN)
			tmp = 1 + (t_ul)(-1 * (n + 1));
		tmp = -1 * n;
		*str = '-';
		p_rec(tmp, base, str + 1, base_s);
		return (str);
	}
	p_rec(n, base, str, base_s);
	return (str);
}

char	*uint_tostr_base(t_ul n, const char *base)
{
	char	*str;
	t_ui	base_s;

	str = crtnumstr_ul(n, base);
	if (!str)
		return ((char *)error(ERROR_BDA));
	base_s = ft_strlen(base);
	p_rec(n, base, str, base_s);
	return (str);
}

const char	*int_tostr(long n, const char *spec, const char *base)
{
	char	*tmp;

	tmp = (char *)spec;
	++tmp;
	--tmp;
	return (int_tostr_base(n, base));
}

const char	*uint_tostr(t_ul n, const char *spec, const char *base)
{
	char	*tmp;

	tmp = (char *)spec;
	++tmp;
	--tmp;
	return (uint_tostr_base(n, base));
}
