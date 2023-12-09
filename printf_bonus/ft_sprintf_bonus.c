/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:25:39 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/09 00:20:19 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>

void	delt_data(void *ptr)
{
	free(((t_data *)ptr)->str);
	free((t_data *)ptr);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !del || !(*lst))
		return ;
	ft_lstclear(&((*lst)->next), del);
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		++count;
	return (count);
}

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

char	*lst_strcpy(t_list *list, char *str)
{
	if (!str)
		return (NULL);
	while (list)
	{
		ft_strcpy(str, ((t_data *)(list->content))->str);
		list = list->next;
	}
	return (str);
}

int		setcountzerro(t_list *list)
{
	t_ui	count;

	count = 0;
	while (list)
	{
		count += ((t_data *)(list->content))->countZerro;
		list = list->next;
	}
	return (count);
}

t_data	*setdata(t_list *list, const char *str ,char *s)
{
	t_data	*data;
	t_ui	count;

	data = t_datacrt(s, 0);
	if (!data)
		return (NULL);
	if (!str)
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
	data = setdata(list, str, s);
	ft_lstclear(&list, &delt_data);
	return (data);
}
