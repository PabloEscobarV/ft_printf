/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:15:25 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/09 23:52:22 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number(const char *base, char ch)
{
	int	num;

	num = 0;
	while (base[num] != ch)
		++num;
	return (num);
}

int	ft_atoi_base(const char *nptr, const char *base)
{
	int	result;
	int	sign;
	int	size_b;

	sign = 1;
	result = 0;
	if (*nptr == '\0')
		return (0);
	size_b = ft_strlen(base);
	while (ft_isspace(*nptr))
		++nptr;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
	}
	while (*nptr && ft_strchr(base, *nptr))
	{
		result = result * size_b + number(base, *nptr);
		++nptr;
	}
	return (result * sign);
}
