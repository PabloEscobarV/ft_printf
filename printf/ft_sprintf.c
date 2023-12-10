/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:25:39 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/10 18:03:09 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>

char	*crt_strlst(t_list *list)
{
	char	*tmp;
	int		size;

	size = 0;
	while (list)
	{
		size += ft_strlen(((t_data *)(list->content))->str);
		list = list->next;
	}
	tmp = ft_calloc((size + 1), sizeof(char));
	return (tmp);
}

t_data	*setdata(t_list *list, char *s)
{
	t_data	*data;
	t_ui	count;

	data = t_datacrt(s, 0);
	if (!data)
		return (NULL);
	count = 0;
	while (list)
	{
		count += ((t_data *)(list->content))->countZerro;
		ft_strcpy(data->str, ((t_data *)(list->content))->str);
		list = list->next;
	}
	data->countZerro = count;
	return (data);
}

t_data	*lst_tostr(const char *str, va_list arg)
{
	t_list	*list;
	t_data	*data;
	char	*s;
	int		count;

	count = count_spec(str);
	if (!count)
		return (ft_strdup_wch(str, DEV));
	list = str_tolst(str, count, arg);
	s = crt_strlst(list);
	if (!s)
		return (error_memaloc(list, &delt_data));
	data = setdata(list, s);
	ft_lstclear(&list, &delt_data);
	return (data);
}
