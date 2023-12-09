/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:14:28 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/07 15:47:31 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

const char	*error(const char *str)
{
	return (ft_strdup(str));
}

const char	*findstart(const char *spc)
{
	while (*spc != DEV)
		--spc;
	return (spc + 1);
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
