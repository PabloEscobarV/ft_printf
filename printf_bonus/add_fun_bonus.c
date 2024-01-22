/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fun_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:14:28 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/11 21:01:51 by polenyc          ###   ########.fr       */
=======
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:14:28 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/20 17:48:54 by polenyc          ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"
<<<<<<< HEAD
=======
#include <stdio.h>
>>>>>>> main

const char	*findstart(const char *spc)
{
	--spc;
	while (*spc != DEV)
		--spc;
	return (spc + 1);
}

t_data	*retres_fin(t_mod *mod, t_data *data, char *s1, char *s2)
{
	modfree(mod);
	data->str = strjoinfree(s1, s2, 2);
	return (data);
}

char	*emptystr(char ch)
{
	char	*tmp;
	int		size;

	size = 1;
	if (ch != '\0')
		size += 1;
	tmp = ft_calloc(size, sizeof(char));
	if (!tmp)
		return (NULL);
	*tmp = ch;
	return (tmp);
}

void	swap(char *s1, char *s2)
{
	char	tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	swap_sign(t_mod *mod, char *str, char *num, char *ch_orig)
{
	char	tmp;
	char	*ch_tmp;

	if (!(*str) || !mod->flags[ZERO] || mod->flags[PREC] || mod->flags[INDENT])
		return ;
	ch_tmp = ch_orig;
	while (!ft_isalnum(*ch_tmp))
		++ch_tmp;
	while (ft_strcmp(num, ch_tmp))
	{
		tmp = *str;
		*str = *num;
		*num = tmp;
		++str;
		++num;
	}
}
