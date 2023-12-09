/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adrtostr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:55:45 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/09 17:35:18 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"
#include <stdlib.h>
#include <stdint.h>

char	*ch_addstr(char *str, char ch)
{
	char	*tmp;

	tmp = str;
	while (*str)
		++str;
	*str = ch;
	*(str + 1) = '\0';
	return (tmp);
}

char	*adr_tostr_base(void *p, const char *base)
{
	int			i;
	int			j;
	uintptr_t	ptr;
	uintptr_t	mask;
	char		*str;

	str = ft_calloc(SIZE_MEM_ADR + 1, sizeof(char));
	if (!str)
		return (NULL);
	mask = UINTPTR_MAX << (sizeof(uintptr_t) * 8 - 4);
	ptr = (uintptr_t)p;
	if (!ptr)
		return (ch_addstr(str, base[0]));
	j = 0;
	while (ptr != 0)
	{
		i = (ptr & mask) >> (sizeof(uintptr_t) * 8 - 4);
		j += i;
		if (j > 0)
			ch_addstr(str, base[i]);
		ptr <<= 4;
	}
	str[SIZE_MEM_ADR] = '\0';
	return (str);
}

char	*hex_mod(t_mod *mod, char *str, char ch)
{
	int		size;
	char	*tmp;

	if (!mod->flags[PREC])
		return (str);
	mod->flags[ZERO] = '\0';
	size = ft_strlen(str);
	if (size >= mod->precision)
		return (str);
	tmp = ft_calloc(mod->precision - size + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	ft_memset(tmp, ch, mod->precision - size);
	return (strjoinfree(tmp, str, 2));
}

char	*addr_mod(t_mod *mod, char *str, char ch)
{
	str = hex_mod(mod, str, ch);
	return (strjoinfree(PRE_HEX_S, str, 1));
}

char	*addhexpre(const char *hex, char *str)
{
	char	*tmp;

	if (!ft_isalnum(*str))
	{
		tmp = strjoinfree(emptystr(*str), (char *)hex, 0);
		tmp = strjoinfree(tmp, str + 1, 0);
		free(str);
		return (tmp);
	}
	return (strjoinfree((char *)hex, str, 1));
}

t_data	*addr_tostr(void *p, const char *spec, const char *base)
{
	t_mod	*mod;
	t_data	*num;
	char	*tmp;
	char	*num_orig;


	if (!(uintptr_t)p)
		return (t_datacrt(ft_strdup("(nil)"), 0));
	num = t_datacrt(uint_tostr_base((uintptr_t)p, base) ,0);
	if (!num)
		return (NULL);
	mod = setmod(spec, MOD, SPEC);
	if (!mod)
		return (NULL);
	num->str = intnum_mod(mod, num, setsign(mod, num), '0');
	if (!num->str)
		return (NULL);
	num_orig = ft_strdup(num->str);
	num->str = addhexpre(PRE_HEX_S, num->str);
	tmp = modnstr_crt(mod, num->str);
	if (!ft_strncmp(tmp, ERROR_BDA, sizeof(ERROR_BDA)))
		return (NULL);
	swap_sign(mod, tmp, num->str, num_orig);
	if (mod->flags[INDENT] == MOD[INDENT])
		return (retres_fin(mod, num, num->str, tmp));
	return (retres_fin(mod, num, tmp, num->str));
}
