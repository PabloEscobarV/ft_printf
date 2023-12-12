/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartostr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:40:57 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/12 22:49:42 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

t_data	*chartostr(const char ch, const char *spec)
{
	t_data	*data;
	t_mod	*mod;
	char	*tmp;

	mod = setmod(spec, MOD, SPEC);
	if (!mod)
		return (NULL);
	if (!ch)
		--mod->size;
	data = t_datacrt(emptystr(ch), 0);
	if (!ch && mod->flags[INDENT])
		--data->countZerro;
	if (!ch && !mod->flags[INDENT])
		++data->countZerro;
	tmp = modstr_crt(mod, ft_strlen(data->str), ' ');
	if (!tmp)
		return (NULL);
	if (mod->flags[INDENT] == MOD[INDENT])
		return (retres_fin(mod, data, data->str, tmp));
	return (retres_fin(mod, data, tmp, data->str));
}
