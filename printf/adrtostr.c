/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adrtostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:55:45 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/07 15:47:37 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
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

const char	*addr_tostr(void *p, const char *spec, const char *base)
{
	char	*tmp;

	tmp = (char *)spec;
	++tmp;
	--tmp;
	return (ft_strjoin_free("0x", uint_tostr((uintptr_t)p, spec, base), 1));
}
