/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:25:39 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/07 15:48:02 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>

void	del_lst(void *ptr)
{
	free((char *)ptr);
}

char	*crt_strlst(t_list *list)
{
	char	*tmp;
	int		size;

	size = 0;
	while (list)
	{
		size += ft_strlen(list->content);
		list = list->next;
	}
	tmp = ft_calloc((size + 1), sizeof(char));
	return (tmp);
}

char	*lst_strcpy(t_list *list, char *str)
{
	if (!str)
		return (NULL);
	while (list)
	{
		ft_strcpy(str, list->content);
		list = list->next;
	}
	return (str);
}

char	*lst_tostr(const char *str, va_list arg)
{
	t_list	*list;
	char	*s;
	int		count;

	count = count_spec(str);
	if (!count)
		return (ft_strdup_wch(str, DEV));
	list = str_tolst(str, count, arg);
	s = crt_strlst(list);
	lst_strcpy(list, s);
	ft_lstclear(&list, &del_lst);
	return (s);
}
