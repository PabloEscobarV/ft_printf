/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_addfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:29:49 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/07 21:44:47 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdlib.h>

size_t	ft_strlen_wch(const char *str, char end, const char ch)
{
	size_t	count;

	count = 0;
	while (*str != '\0' && *str != end)
	{
		if (*str == ch)
			++str;
		++count;
		++str;
	}
	return (count);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*tmp;

	if (!(*src))
		return (dest);
	tmp = dest;
	while (*dest)
		++dest;
	while (*src)
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = '\0';
	return (tmp);
}

char	*str_tostr(const char *start, const char *end, const char dev)
{
	char	*str;
	size_t	len;

	len = 0;
	end = findstart(end);
	--end;
	len = ft_strlen_wch(start, *end, dev);
	if (!len)
		return (emptystr('\0'));
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	len = -1;
	while (++len + start < end)
	{
		if (start[len] == dev)
			++start;
		str[len] = start[len];
	}
	str[len] = '\0';
	return (str);
}

char	*ft_strdup_wch(const char *src, char dev)
{
	char	*tmp;
	char	*ret_tmp;
	size_t	size;

	size = ft_strlen_wch(src, '\0', dev);
	tmp = (char *)malloc((size + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	ret_tmp = tmp;
	while (size--)
	{
		if (*src == dev)
			++src;
		*tmp = *src;
		++src;
		++tmp;
	}
	*tmp = '\0';
	return (ret_tmp);
}

const char	*ft_strjoin_free(const char *s1, const char *s2, int pos)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (pos < 0)
		return (tmp);
	if (pos == 0)
	{
		free((char *)s1);
		return (tmp);
	}
	if (pos == 1)
	{
		free((char *)s2);
		return (tmp);
	}
	free((char *)s1);
	free((char *)s2);
	return (tmp);
}
