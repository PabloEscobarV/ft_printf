/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:07:27 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/10 17:14:54 by polenyc          ###   ########.fr       */
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
	
 	size_p += printf("| %-1c %-2c %-3.20c |\n", 0, 'X', 'X');
	size_f += ft_printf("| %-1c %-2c %-3.20c |\n", 0, 'X', 'X');

	size_p += printf("|%+.10d|\n", -14);
	size_f += ft_printf("|%+.10d|\n", -14);

	size_p += printf("| %05d |\n", -15);
	size_f += ft_printf("| %05d |\n", -15);

	size_p += printf("| %06d |\n", -16);
	size_f += ft_printf("| %06d |\n", -16);

	size_p += printf("| %011d |\n", LONG_MAX);
	size_f += ft_printf("| %011d |\n", LONG_MAX);

	size_p += printf("| %013d |\n", UINT_MAX);
	size_f += ft_printf("| %013d |\n", UINT_MAX);

	size_p += printf("| %014d |\n", ULONG_MAX);
	size_f += ft_printf("| %014d |\n", ULONG_MAX);

	size_p += printf("| %015d |\n", 9223372036854775807LL);
	size_f += ft_printf("| %015d |\n", 9223372036854775807LL);


	size_p += printf("| %09d %010d %011d %012d %013d %014d %015d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	size_f += ft_printf("| %09d %010d %011d %012d %013d %014d %015d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	size_p += printf("| %05i |\n", -15);
	size_f += ft_printf("| %05i |\n", -15);

	size_p += printf("| %06i |\n", -16);
	size_f += ft_printf("| %06i |\n", -16);

	size_p += printf("| %01i |\n", -99);		
	size_f += ft_printf("| %01i |\n", -99);

	size_p += printf("| %012i |\n", LONG_MIN);
	size_f += ft_printf("| %012i |\n", LONG_MIN);

	size_p += printf("| %014i |\n", ULONG_MAX);
	size_f += ft_printf("| %014i |\n", ULONG_MAX);

	size_p += printf("| %015i |\n", 9223372036854775807LL);
	size_f += ft_printf("| %015i |\n", 9223372036854775807LL);

	size_p += printf("| %09i %010i %011i %012i %013i %014i %015i|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	size_f += ft_printf("| %09i %010i %011i %012i %013i %014i %015i|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	
	size_p += printf("| %01u |\n", 0);
	size_f += ft_printf("| %01u |\n", 0);

	size_p += printf("|% 010d|\n", 42);
	size_f += ft_printf("|% 010d|\n", 42);

	size_p += printf("| %.s |\n", "-");
	size_f += ft_printf("| %.s |\n", "-");

	size_p += printf("| %.2d |\n", -1);
	size_f += ft_printf("| %.2d |\n", -1);

	size_p += printf("| %.3d |\n", -11);
	size_f += ft_printf("| %.3d |\n", -11);

	size_p += printf("| %.4d |\n", -14);
	size_f += ft_printf("| %.4d |\n", -14);

	size_p += printf("| %.3d |\n", -99);
	size_f += ft_printf("| %.3d |\n", -99);

	size_p += printf("| %.4d |\n", -101);
	size_f += ft_printf("| %.4d |\n", -101);

	size_p += printf("| %.10d |\n", LONG_MAX);
	size_f += ft_printf("| %.10d |\n", LONG_MAX);

	size_p += printf("| %.12d |\n", UINT_MAX);
	size_f += ft_printf("| %.12d |\n", UINT_MAX);

	size_p += printf("| %.13d |\n", ULONG_MAX);
	size_f += ft_printf("| %.13d |\n", ULONG_MAX);

	size_p += printf("| %.14d |\n", 9223372036854775807LL);
	size_f += ft_printf("| %.14d |\n", 9223372036854775807LL);

	size_p += printf("| %.8d %.9d %.10d %.11d %.12d %.13d %.14d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	size_f += ft_printf("| %.8d %.9d %.10d %.11d %.12d %.13d %.14d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	size_p += printf("| %.2i |\n", -1);
	size_f += ft_printf("| %.2i |\n", -1);

	size_p += printf("| %.3i |\n", -11);
	size_f += ft_printf("| %.3i |\n", -11);

	size_p += printf("| %.4i |\n", -14);
	size_f += ft_printf("| %.4i |\n", -14);

	size_p += printf("| %.3i |\n", -99);
	size_f += ft_printf("| %.3i |\n", -99);

	size_p += printf("| %.4i |\n", -101);
	size_f += ft_printf("| %.4i |\n", -101);

	size_p += printf("| %.10i |\n", LONG_MAX);
	size_f += ft_printf("| %.10i |\n", LONG_MAX);

	size_p += printf("| %.12i |\n", UINT_MAX);
	size_f += ft_printf("| %.12i |\n", UINT_MAX);

	size_p += printf("| %.13i |\n", ULONG_MAX);
	size_f += ft_printf("| %.13i |\n", ULONG_MAX);

	size_p += printf("| %.14i |\n", 9223372036854775807LL);
	size_f += ft_printf("| %.14i |\n", 9223372036854775807LL);

	size_p += printf("| %.8i %.9i %.10i %.11i %.12i %.13i %.14i|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	size_f += ft_printf("| %.8i %.9i %.10i %.11i %.12i %.13i %.14i|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

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
			
	size_p += printf("| %x |\n", LONG_MAX);
	size_f += ft_printf("| %x |\n", LONG_MAX);

	size_p += printf("| %x |\n", LONG_MIN);
	size_f += ft_printf("| %x |\n", LONG_MIN);

	size_p += printf("| %x |\n", ULONG_MAX);
	size_f += ft_printf("| %x |\n", ULONG_MAX);

	size_p += printf("| %x |\n", 9223372036854775807LL);
	size_f += ft_printf("| %x |\n", 9223372036854775807LL);

	size_p += printf("| %x %x %x %x %x %x %x|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	size_f += ft_printf("| %x %x %x %x %x %x %x|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	size_p += printf("| %u |\n", LONG_MAX);
	size_f += ft_printf("| %u |\n", LONG_MAX);
	
	size_p += printf("| %u |\n", LONG_MIN);
	size_f += ft_printf("| %u |\n", LONG_MIN);

	size_p += printf("| %u |\n", ULONG_MAX);
	size_f += ft_printf("| %u |\n", ULONG_MAX);

	size_p += printf("| %u |\n", 9223372036854775807LL);
	size_f += ft_printf("| %u |\n", 9223372036854775807LL);

	size_p += printf("| %u %u %u %u %u %u %u|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	size_f += ft_printf("| %u %u %u %u %u %u %u|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	size_p += printf("| %p |\n", 16);
	size_f += ft_printf("| %p |\n", 16);

	size_p += printf("| %p %p |\n", LONG_MIN, LONG_MAX);
	size_f += ft_printf("| %p %p |\n", LONG_MIN, LONG_MAX);

	size_p += printf("| %p %p |\n", INT_MIN, INT_MAX);
	size_f += ft_printf("| %p %p |\n", INT_MIN, INT_MAX);

	size_p += printf("| %p %p |\n", ULONG_MAX, -ULONG_MAX);
	size_f += ft_printf("| %p %p |\n", ULONG_MAX, -ULONG_MAX);

	size_p += printf("| %.4d |\n", -101);
	size_f += ft_printf("| %.4d |\n", -101);

	size_f += ft_printf("| %p %p |\n", 0, 0);
	size_p += printf("| %p %p |\n", 0, 0);
	
	size_p += printf("|%s|\n", "");
	size_f += ft_printf("|%s|\n", "");
	
	size_p += printf("| %s|\n", "");
	size_f += ft_printf("| %s|\n", "");
	
	size_p += printf("|%s |\n", "");
	size_f += ft_printf("|%s |\n", "");

	size_p += printf("| %s |\n", "");
	size_f += ft_printf("| %s |\n", "");

	size_p += printf("| %s %s |\n", "", "-");
	size_f += ft_printf("| %s %s |\n", "", "-");

	size_p += printf("| %s %s |\n", " - ", "");
	size_f += ft_printf("| %s %s |\n", " - ", "");

	size_p += printf("| %s %s %s %s %s|\n", " - ", "", "4", "", s2);
	size_f += ft_printf("| %s %s %s %s %s|\n", " - ", "", "4", "", s2);

	size_p += printf("| %s %s %s %s %s |\n", " - ", "", "4", "", "2 ");
	size_f += ft_printf("| %s %s %s %s %s |\n", " - ", "", "4", "", "2 ");

	size_f += ft_printf("| %#x |\n", LONG_MIN);
	size_p += printf("| %#x |\n", LONG_MIN);

	size_f += ft_printf("| %#x %#x %#x %#x %#x %#x %#x|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	size_p += printf("| %#x %#x %#x %#x %#x %#x %#x|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	size_f += ft_printf("| %#X |\n", 0);
	size_p += printf("| %#X |\n", 0);


	size_f += ft_printf("| %#X %#X %#X %#X %#X %#X %#X|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	size_p += printf("| %#X %#X %#X %#X %#X %#X %#X|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	size_f += ft_printf("| %#X |\n", LONG_MIN);
	size_p += printf("| %#X |\n", LONG_MIN);

	size_f += ft_printf("| % d |\n", -1);
	size_p += printf("| % d |\n", -1);

	size_f += ft_printf("| % d |\n", -9);
	size_p += printf("| % d |\n", -9);

	size_f += ft_printf("| % d |\n", -10);
	size_p += printf("| % d |\n", -10);
	
	size_f += ft_printf("| % d |\n", -11);
	size_p += printf("| % d |\n", -11);
	
	size_f += ft_printf("| % d |\n", -14);	
	size_p += printf("| % d |\n", -14);

	size_f += ft_printf("| % d |\n", -15);
	size_p += printf("| % d |\n", -15);
	
	size_f += ft_printf("| % d |\n", -16);
	size_p += printf("| % d |\n", -16);
	
	size_f += ft_printf("| % d |\n", -99);
	size_p += printf("| % d |\n", -99);
	
	size_f += ft_printf("| % d |\n", -100);
	size_p += printf("| % d |\n", -100);
	
	size_f += ft_printf("| % d |\n", -101);
	size_p += printf("| % d |\n", -101);
	
	size_f += ft_printf("| % d |\n", INT_MIN);
	size_p += printf("| % d |\n", INT_MIN);
	
	size_f += ft_printf(" % d ", LONG_MAX);
	size_p += printf(" % d ", LONG_MAX);
	
	size_f += ft_printf(" % d ", UINT_MAX);
	size_p += printf(" % d ", UINT_MAX);
	
	size_f += ft_printf("| % d |\n", ULONG_MAX);
	size_p += printf("| % d |\n", ULONG_MAX);
	
	size_f += ft_printf("| % d |\n", 9223372036854775807LL);
	size_p += printf("| % d |\n", 9223372036854775807LL);
	
	size_f += ft_printf("| % d % d % d % d % d % d % d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	size_p += printf("| % d % d % d % d % d % d % d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	
	size_f += ft_printf("| % i |\n", -1);
	size_p += printf("| % i |\n", -1);
	
	size_f += ft_printf("| % i |\n", -9);
	size_p += printf("| % i |\n", -9);
	
	size_f += ft_printf("| % i |\n", -10);
	size_p += printf("| % i |\n", -10);
	
	size_f += ft_printf("| % i |\n", -11);
	size_p += printf("| % i |\n", -11);
	
	size_f += ft_printf("| % i |\n", -14);
	size_p += printf("| % i |\n", -14);
	
	size_f += ft_printf("| % i |\n", -15);
	size_p += printf("| % i |\n", -15);
	
	size_f += ft_printf("| % i |\n", -16);
	size_p += printf("| % i |\n", -16);
	
	size_f += ft_printf("| % i |\n", -99);
	size_p += printf("| % i |\n", -99);
	
	size_f += ft_printf("| % i |\n", -100);
	size_p += printf("| % i |\n", -100);
	
	size_f += ft_printf("| % i |\n", -101);
	size_p += printf("| % i |\n", -101);
	
	size_f += ft_printf("| % i |\n", INT_MIN);
	size_p += printf("| % i |\n", INT_MIN);
	
	size_f += ft_printf("| % i |\n", LONG_MAX);
	size_p += printf("| % i |\n", LONG_MAX);
	
	size_f += ft_printf("| % i |\n", UINT_MAX);
	size_p += printf("| % i |\n", UINT_MAX);
	
	size_f += ft_printf("| % i |\n", ULONG_MAX);
	size_p += printf("| % i |\n", ULONG_MAX);
	
	size_f += ft_printf("| % i |\n", 9223372036854775807LL);
	size_p += printf("| % i |\n", 9223372036854775807LL);

	size_f += ft_printf("| % i % i % i % i % i % i % i|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	size_p += printf("| % i % i % i % i % i % i % i|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	
	size_f += ft_printf("| %+d |\n", -1);
	size_p += printf("| %+d |\n", -1);
	
	size_f += ft_printf("| %+d |\n", -9);
	size_p += printf("| %+d |\n", -9);
	
	size_f += ft_printf("| %+d |\n", -10);
	size_p += printf("| %+d |\n", -10);
	
	size_f += ft_printf("| %+d |\n", -11);
	size_p += printf("| %+d |\n", -11);
	
	size_f += ft_printf("| %+d |\n", -14);
	size_p += printf("| %+d |\n", -14);
	
	size_f += ft_printf("| %+d |\n", -15);
	size_p += printf("| %+d |\n", -15);
	
	size_f += ft_printf("| %+d |\n", -16);
	size_p += printf("| %+d |\n", -16);
	
	size_f += ft_printf("| %+d |\n", -99);
	size_p += printf("| %+d |\n", -99);
	
	size_f += ft_printf("| %+d |\n", -100);
	size_p += printf("| %+d |\n", -100);

	size_f += ft_printf("| %+d |\n", -101);
	size_p += printf("| %+d |\n", -101);

	size_f += ft_printf("| %+d |\n", INT_MIN);
	size_p += printf("| %+d |\n", INT_MIN);

	size_f += ft_printf("| %+d |\n", UINT_MAX);
	size_p += printf("| %+d |\n", UINT_MAX);

	size_f += ft_printf("| %+d |\n", ULONG_MAX);
	size_p += printf("| %+d |\n", ULONG_MAX);

	size_f += ft_printf("| %+d |\n", 9223372036854775807LL);
	size_p += printf("| %+d |\n", 9223372036854775807LL);

	size_f += ft_printf("| %+d %+d %+d %+d %+d %+d %+d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	size_p += printf("| %+d %+d %+d %+d %+d %+d %+d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	size_f += ft_printf("| %+i |\n", -9);
	size_p += printf("| %+i |\n", -9);

	size_f += ft_printf("| %+i |\n", -10);
	size_p += printf("| %+i |\n", -10);

	size_f += ft_printf("| %+i |\n", -11);
	size_p += printf("| %+i |\n", -11);

	size_f += ft_printf("| %+i |\n", -14);
	size_p += printf("| %+i |\n", -14);

	size_f += ft_printf("| %+i |\n", -15);
	size_p += printf("| %+i |\n", -15);

	size_f += ft_printf("| %+i |\n", -16);
	size_p += printf("| %+i |\n", -16);

	size_f += ft_printf("| %+i |\n", -99);
	size_p += printf("| %+i |\n", -99);

	size_f += ft_printf("| %+i |\n", -100);
	size_p += printf("| %+i |\n", -100);

	size_f += ft_printf("| %+i |\n", -101);
	size_p += printf("| %+i |\n", -101);

	size_f += ft_printf("| %+i |\n", INT_MAX);
	size_p += printf("| %+i |\n", INT_MAX);

	size_f += ft_printf("| %+i |\n", LONG_MAX);
	size_p += printf("| %+i |\n", LONG_MAX);

	size_f += ft_printf("| %+i |\n", LONG_MIN);
	size_p += printf("| %+i |\n", LONG_MIN);

	size_f += ft_printf("| %+i |\n", ULONG_MAX);
	size_p += printf("| %+i |\n", ULONG_MAX);

	size_f += ft_printf("| %+i |\n", 9223372036854775807LL);
	size_p += printf("| %+i |\n", 9223372036854775807LL);

	size_f += ft_printf("| %+i %+i %+i %+i %+i %+i %+i|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	size_p += printf("| %+i %+i %+i %+i %+i %+i %+i|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	
	size_p += printf("| NULL %s NULL |\n", NULL);
	size_f += ft_printf("| NULL %s NULL |\n", NULL);

	size_p += printf("| %c %c %c |\n", 0, '1', '2');
	size_f += ft_printf("| %c %c %c |\n", 0, '1', '2');

	printf("%s\n", "Darova");
    ft_printf("%s\n", "Darova");

	size_p += printf("|%c|\t|%c|\t|%c|\n", 'c', 'c', 'c');
	size_f += ft_printf("|%c|\t|%c|\t|%c|\n", 'c', 'c', 'c');

	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	size_p += printf("|%-3c|\n", 0);
	size_f += ft_printf("|%-3c|\n", 0);

	size_p += printf("| %-1c %-2c %-3c |\n", '0', 0, '1');
	size_f += ft_printf("| %-1c %-2c %-3c |\n", '0', 0, '1');

	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
 	size_p += printf("| %-1c %-2c %-3c |\n", '2', '1', 0);
	size_f += ft_printf("| %-1c %-2c %-3c |\n", '2', '1', 0);

	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
 	size_p += printf("| %-1c %-2c %-3c |\n", 0, '1', '2');
	size_f += ft_printf("| %-1c %-2c %-3c |\n", 0, '1', '2');

	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	size_p += printf("|%s|\t|%10s|\t|%-10s|\t|%10s|\t|%-10s|\t|%10.5s|\t|%-10.3s|\t|%-10.3s|\n", "string", "string", "string", "string", "string", "string", "string", "");
	size_f += ft_printf("|%s|\t|%10s|\t|%-10s|\t|%10s|\t|%-10s|\t|%10.5s|\t|%-10.3s|\t|%-10.3s|\n", "string", "string", "string", "string", "string", "string", "string", "");
	
	size_p += printf("|%+-010.3d|\t|%+-010.15d|\n", 42, 42, 42);
	size_f += ft_printf("|%+-010.3d|\t|%+-010.15d|\n", 42, 42, 42);	
	
	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	size_p += printf("|%d|\t|%10d|\t|%-10d|\t|% 0d|\t|%-010d|\t|%+-10d|\t|%+-010.3d|\t|%+-010.15d|\n", 42, 42, 42, 42, 42, 42, 42, 42);
	size_f += ft_printf("|%d|\t|%10d|\t|%-10d|\t|% 0d|\t|%-010d|\t|%+-10d|\t|%+-010.3d|\t|%+-010.15d|\n", 42, 42, 42, 42, 42, 42, 42, 42);
	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	size_p += printf("|%i|\t|%10i|\t|%-10i|\t|%010i|\t|%-010i|\t|%+-10i|\t|%+-010.3i|\n", 42, 42, 42, 42, 42, 42, 42);
	size_f += ft_printf("|%i|\t|%10i|\t|%-10i|\t|%010i|\t|%-010i|\t|%+-10i|\t|%+-010.3i|\n", 42, 42, 42, 42, 42, 42, 42);
	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	size_p += printf("|%u|\t|%10u|\t|%-10u|\t|%010u|\t|%-010u|\t|%+-10u|\t|%+-010.3u|\n", 42, 42, 42, 42, 42, 42, 42);
	size_f += ft_printf("|%u|\t|%10u|\t|%-10u|\t|%010u|\t|%-010u|\t|%+-10u|\t|%+-010.3u|\n", 42, 42, 42, 42, 42, 42, 42);
	size_p += printf("|%+-010.3f|\t|%+-010.15f|\n", 3.14, 3.14);
	size_f += ft_printf("|%+-010.3f|\t|%+-010.15f|\n", 3.14, 3.14);
	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	size_p += printf("|%f|\t|%10f|\t|%-10f|\t|%010f|\t|%-010f|\t|%+-10f|\t|%+-010.3f|\t|%+-010.15f|\n", 3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14);
	size_f += ft_printf("|%f|\t|%10f|\t|%-10f|\t|%010f|\t|%-010f|\t|%+-10f|\t|%+-010.3f|\t|%+-010.15f|\n", 3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14, 3.14);
	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	size_p += printf("|%020p|\t|%+020.3p|\n", (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8);
	size_f += ft_printf("|%020p|\t|%+020.3p|\n", (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8);

	size_p += printf("|%p|\t|%20p|\t|%-20p|\t|%020p|\t|%-020p|\t|%+020p|\t|%+020.3p|\n", (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8);
	size_f += ft_printf("|%p|\t|%20p|\t|%-20p|\t|%020p|\t|%-020p|\t|%+020p|\t|%+020.3p|\n", (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8, (void *)0x7ffeec85e6b8);
	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	size_p += printf("|%x|\t|%10x|\t|%-10x|\t|%010x|\t|%-010x|\t|%+-10x|\t|%+-#010.3x|\t|%x|\n", 255, 255, 255, 255, 255, 255, 255, 0);
	size_f += ft_printf("|%x|\t|%10x|\t|%-10x|\t|%010x|\t|%-010x|\t|%+-10x|\t|%+-#010.3x|\t|%x|\n", 255, 255, 255, 255, 255, 255, 255, 0);
	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	size_p += printf("|%X|\t|%10X|\t|%-10X|\t|%010X|\t|%-010X|\t|%+-10X|\t|%+-#010.3X|\t|%+#020.15X|\n", 255, 255, 255, 255, 255, 255, 255, 255);
	size_f += ft_printf("|%X|\t|%10X|\t|%-10X|\t|%010X|\t|%-010X|\t|%+-10X|\t|%+-#010.3X|\t|%+#020.15X|\n", 255, 255, 255, 255, 255, 255, 255, 255);
	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	size_p += ft_printf("%s\n", str);
	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	size_f += printf("%s\n", str);
	ft_printf("\n--------------------///////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\--------------------------------\n\n");
	printf("result size_p: %d\n", size_p);
	ft_printf("result size_f: %d\n", size_f);
	free(str);
    return (0);
}
