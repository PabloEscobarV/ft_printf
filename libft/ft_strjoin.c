/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:46:07 by polenyc           #+#    #+#             */
/*   Updated: 2023/11/19 22:15:02 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strcpy(char *dest, char const *src)
{
	while (*src != 0)
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	char	*tmp;
	size_t	size1;
	size_t	size2;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	arr = malloc((size1 + size2 + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	tmp = ft_strcpy(arr, s1);
	ft_strcpy(tmp, s2);
	return (arr);
}
