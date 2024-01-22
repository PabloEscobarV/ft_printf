/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:25:39 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/12 12:49:20 by polenyc          ###   ########.fr       */
=======
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:25:39 by polenyc           #+#    #+#             */
/*   Updated: 2024/01/22 14:10:16 by polenyc          ###   ########.fr       */
>>>>>>> main
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
<<<<<<< HEAD
		count += ((t_data *)(list->content))->countZerro;
		ft_strcpy(data->str, ((t_data *)(list->content))->str);
		list = list->next;
	}
	data->countZerro = count;
=======
		count += ((t_data *)(list->content))->countzerro;
		ft_strcpy_tend(data->str, ((t_data *)(list->content))->str);
		list = list->next;
	}
	data->countzerro = count;
>>>>>>> main
	return (data);
}

t_data	*lst_tostr(const char *str, va_list arg)
{
	t_list	*list;
	t_data	*data;
	char	*s;

	list = str_tolst(str, arg);
	s = crt_strlst(list);
	if (!s)
		return (error_memaloc(list, &delt_data));
	data = setdata(list, s);
	ft_lstclear(&list, &delt_data);
	return (data);
}

<<<<<<< HEAD
=======
int	printch(t_data *data)
{
	if (data->countzerro == 0)
		return (0);
	if (data->countzerro > 0)
	{
		ft_putstr(data->str);
		ft_putchar('\0');
		return (ft_strlen(data->str) + 1);
	}
	ft_putchar('\0');
	ft_putstr(data->str);
	return (ft_strlen(data->str) + 1);
}
>>>>>>> main

int	printdata(const char *str, va_list arg)
{
	t_list	*list;
	t_list	*tmp;
	int		count;

	list = str_tolst(str, arg);
	if (!list)
<<<<<<< HEAD
	{
		ft_putstr(ERROR_BDA);
		return (ft_strlen(ERROR_BDA));
	}
=======
		return (-1);
>>>>>>> main
	tmp = list;
	count = 0;
	while (tmp)
	{
<<<<<<< HEAD
		ft_putstr(((t_data *)tmp->content)->str);
		count += ft_strlen(((t_data *)tmp->content)->str);
		count += ((t_data *)tmp->content)->countZerro;
=======
		if (((t_data *)tmp->content)->countzerro != 0)
		{
			count += printch(tmp->content);
			tmp = tmp->next;
			continue ;
		}
		ft_putstr(((t_data *)tmp->content)->str);
		count += ft_strlen(((t_data *)tmp->content)->str);
		count += ((t_data *)tmp->content)->countzerro;
>>>>>>> main
		tmp = tmp->next;
	}
	ft_lstclear(&list, &delt_data);
	return (count);
}
