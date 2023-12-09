/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:02:30 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/07 15:48:06 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdlib.h>

const char	*hex_tostr(long n, const char *spec, const char *base, char *p_h)
{
	const char	*tmp;

	tmp = spec;
	tmp = p_h;
	++tmp;
	return (int_tostr_base(n, base));
}
