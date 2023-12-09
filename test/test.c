/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:07:27 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/07 22:27:25 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "headers/ft_printf.h"
#include "headers/ft_printf_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

size_t	filesize(const char *filename)
{
	int		file;
	size_t	size;
	char	tmp;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return (0);
	size = 0;
	while (read(file, &tmp, sizeof(tmp)))
		++size;
	close(file);
	return (size);
}

char	*readdata(const char *filename)
{
	size_t	size;
	int		file;
	char	*tmp;
	char	*str;
	char	ch;

	size = filesize(filename);
	if (!size)
		return (NULL);
	str = calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	file = open(filename, O_RDONLY);
	tmp = str;
	if (file < 0)
		return (NULL);
	while (read(file, &ch, sizeof(ch)))
	{
		*tmp = ch;
		++tmp;
	}
	close(file);
	*tmp = '\0';
	return (str);
}

int main (void)
{
	int 	size_p;
	int 	size_f;
	char	*str;
	char 	s2[] = "abcd efgh 67580 78";

	str = readdata("test.txt");
	if (!str)
		ft_printf("ERRORRRR!!!!!\n\n");
	size_p = 0;
	size_f = 0;
	
	size_p += printf("| %% |\n");
	size_f += ft_printf("| %% |\n");
	
	size_p += printf("| %%%% |\n");
	size_f += ft_printf("| %%%% |\n");

	size_p += printf("| %% %% %% |\n");
	size_f += ft_printf("| %% %% %% |\n");

	size_p += printf("| %%  %%  %% |\n");
	size_f += ft_printf("| %%  %%  %% |\n");

	size_p += printf("|%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%|\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	size_f += ft_printf("|%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%|\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
			
	// size_p += printf("| %x |\n", LONG_MAX);
	// size_f += ft_printf("| %x |\n", LONG_MAX);

	// size_p += printf("| %x |\n", LONG_MIN);
	// size_f += ft_printf("| %x |\n", LONG_MIN);

	// size_p += printf("| %x |\n", ULONG_MAX);
	// size_f += ft_printf("| %x |\n", ULONG_MAX);

	// size_p += printf("| %x |\n", 9223372036854775807LL);
	// size_f += ft_printf("| %x |\n", 9223372036854775807LL);

	// size_p += printf("| %x %x %x %x %x %x %x|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// size_f += ft_printf("| %x %x %x %x %x %x %x|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	// size_p += printf("| %u |\n", LONG_MAX);
	// size_f += ft_printf("| %u |\n", LONG_MAX);
	
	// size_p += printf("| %u |\n", LONG_MIN);
	// size_f += ft_printf("| %u |\n", LONG_MIN);

	// size_p += printf("| %u |\n", ULONG_MAX);
	// size_f += ft_printf("| %u |\n", ULONG_MAX);

	// size_p += printf("| %u |\n", 9223372036854775807LL);
	// size_f += ft_printf("| %u |\n", 9223372036854775807LL);

	// size_p += printf("| %u %u %u %u %u %u %u|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// size_f += ft_printf("| %u %u %u %u %u %u %u|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// size_p += printf("| %p |\n", 16);
	// size_f += ft_printf("| %p |\n", 16);

	// size_p += printf("| %p %p |\n", LONG_MIN, LONG_MAX);
	// size_f += ft_printf("| %p %p |\n", LONG_MIN, LONG_MAX);

	// size_p += printf("| %p %p |\n", INT_MIN, INT_MAX);
	// size_f += ft_printf("| %p %p |\n", INT_MIN, INT_MAX);

	size_p += printf("| %p %p |\n", ULONG_MAX, -ULONG_MAX);
	size_f += ft_printf("| %p %p |\n", ULONG_MAX, -ULONG_MAX);

	// size_p += printf("| %p %p |\n", 0, 0);
	// size_f += ft_printf("| %p %p |\n", 0, 0);
	
	// size_p += printf("|%s|\n", "");
	// size_f += ft_printf("|%s|\n", "");
	
	// size_p += printf("| %s|\n", "");
	// size_f += ft_printf("| %s|\n", "");
	
	// size_p += printf("|%s |\n", "");
	// size_f += ft_printf("|%s |\n", "");

	// size_p += printf("| %s |\n", "");
	// size_f += ft_printf("| %s |\n", "");

	// size_p += printf("| %s %s |\n", "", "-");
	// size_f += ft_printf("| %s %s |\n", "", "-");

	// size_p += printf("| %s %s |\n", " - ", "");
	// size_f += ft_printf("| %s %s |\n", " - ", "");

	// size_p += printf("| %s %s %s %s %s|\n", " - ", "", "4", "", s2);
	// size_f += ft_printf("| %s %s %s %s %s|\n", " - ", "", "4", "", s2);

	// size_p += printf("| %s %s %s %s %s |\n", " - ", "", "4", "", "2 ");
	// size_f += ft_printf("| %s %s %s %s %s |\n", " - ", "", "4", "", "2 ");

	// size_p += printf("| NULL %s NULL |\n", NULL);
	// size_f += ft_printf("| NULL %s NULL |\n", NULL);
	// size_p += printf("| %c %c %c |\n", 0, '1', '2');
	// size_f += ft_printf("| %c %c %c |\n", 0, '1', '2');
	// printf("%s\n", "Darova");
    // ft_printf("%s\n", "Darova");
	// size_p += printf("|%c|\t|%c|\t|%c|\n", 'c', 'c', 'c');
	// size_f += ft_printf("|%c|\t|%c|\t|%c|\n", 'c', 'c', 'c');
	// ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
    // size_p += printf("|%s|\t|%10s|\t|%-10s|\t|%10s|\t|%-10s|\t|%10.5s|\t|%-10.3s|\t|%-10.3s|\n", "string", "string", "string", "string", "string", "string", "string", "");
	// size_f += ft_printf("|%s|\t|%10s|\t|%-10s|\t|%10s|\t|%-10s|\t|%10.5s|\t|%-10.3s|\t|%-10.3s|\n", "string", "string", "string", "string", "string", "string", "string", "");
	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	size_p += printf("|%d|\t|%10d|\t|%-10d|\t|% 010d|\t|%-010d|\t|%+-10d|\t|%+-010.3d|\t|%+-010.15d|\n", 42, 42, 42, 42, 42, 42, 42, 42);
	size_f += ft_printf("|%d|\t|%10d|\t|%-10d|\t|% 010d|\t|%-010d|\t|%+-10d|\t|%+-010.3d|\t|%+-010.15d|\n", 42, 42, 42, 42, 42, 42, 42, 42);
	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	// size_p += printf("|%i|\t|%10i|\t|%-10i|\t|%010i|\t|%-010i|\t|%+-10i|\t|%+-010.3i|\n", 42, 42, 42, 42, 42, 42, 42);
	// size_f += ft_printf("|%i|\t|%10i|\t|%-10i|\t|%010i|\t|%-010i|\t|%+-10i|\t|%+-010.3i|\n", 42, 42, 42, 42, 42, 42, 42);
	// ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	// size_p += printf("|%u|\t|%10u|\t|%-10u|\t|%010u|\t|%-010u|\t|%+-10u|\t|%+-010.3u|\n", 42, 42, 42, 42, 42, 42, 42);
	// size_f += ft_printf("|%u|\t|%10u|\t|%-10u|\t|%010u|\t|%-010u|\t|%+-10u|\t|%+-010.3u|\n", 42, 42, 42, 42, 42, 42, 42);
	// ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	// size_p += printf("|%f|\t|%10f|\t|%-10f|\t|%010f|\t|%-010f|\t|%+-10f|\t|%+-010.3f|\t|%+-010.15f|\n", 3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14);
	// size_f += ft_printf("|%f|\t|%10f|\t|%-10f|\t|%010f|\t|%-010f|\t|%+-10f|\t|%+-010.3f|\t|%+-010.15f|\n", 3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14);
	// ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	// size_p += printf("|%p|\t|%20p|\t|%-20p|\t|%020p|\t|%-020p|\t|%+020p|\t|%+020.3p|\n", (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8);
	// size_f += ft_printf("|%p|\t|%20p|\t|%-20p|\t|%020p|\t|%-020p|\t|%+020p|\t|%+020.3p|\n", (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8);
	// ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	// size_p += printf("|%x|\t|%10x|\t|%-10x|\t|%010x|\t|%-010x|\t|%+-10x|\t|%+-#010.3x|\n", 255, 255, 255, 255, 255, 255, 255);
	// size_f += ft_printf("|%x|\t|%10x|\t|%-10x|\t|%010x|\t|%-010x|\t|%+-10x|\t|%+-#010.3x|\n", 255, 255, 255, 255, 255, 255, 255);
	// ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	// size_p += printf("|%X|\t|%10X|\t|%-10X|\t|%010X|\t|%-010X|\t|%+-10X|\t|%+-#010.3X|\t|%+#020.15X|\n", 255, 255, 255, 255, 255, 255, 255, 255);
	// size_f += ft_printf("|%X|\t|%10X|\t|%-10X|\t|%010X|\t|%-010X|\t|%+-10X|\t|%+-#010.3X|\t|%+#020.15X|\n", 255, 255, 255, 255, 255, 255, 255, 255);
	// ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	// size_p += ft_printf("%s\n", str);
	// ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	// size_f += printf("%s\n", str);
	// ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	printf("result size_p: %d\n", size_p);
	ft_printf("result size_f: %d\n", size_f);
	free(str);
    return (0);
}
