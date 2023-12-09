/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:36:19 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/07 15:48:33 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdlib.h>

const char	*tostr_mod(const char *str, const char *spec)
{
	char	*tmp;

	tmp = (char *)spec;
	++tmp;
	--tmp;
	if (!str)
		return (ft_strdup("(null)"));
	if (*str != 0)
		return (ft_strjoin(str, ""));
	return (emptystr('\0'));
}
