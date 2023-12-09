/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:09:10 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/07 15:33:28 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define SPEC			"scdiufpxX"
#define MOD				"-0+#. "
#define DEV				'%'
#define FDOT			'.'
#define HEX_L			"0123456789ABCDEF"
#define HEX_S			"0123456789abcdef"
#define DEC				"0123456789"
#define BIN				"01"
#define ERROR_BDA		"***BAD MAMMORY ALLOC!***"
#define SIZE_MEM_ADR	16
#define PRE_HEX_S		"0x"
#define PRE_HEX_L		"0X"
#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

typedef unsigned int	t_ui;
typedef unsigned long	t_ul;
typedef unsigned char	t_uch;
typedef struct s_mod
{
	t_uch	*flags;
	int		precision;
	int		size;
}			t_mod;
enum
{
	INDENT,
	ZERO,
	SIGN,
	HEX,
	PREC,
	SPACE,
};

int			ft_printf(const char *spec, ...);
char		*lst_tostr(const char *str, va_list arg);
t_list		*str_tolst(const char *str, int count, va_list arg);
//////////////////////////////////////STRING//////////////////////////////////
const char	*tostr_mod(const char *str, const char *spec);
char		*ft_strdup_wch(const char *src, char dev);
const char	*ft_strjoin_free(const char *s1, const char *s2, int pos);
char		*ft_strcpy(char *dest, const char *src);
char		*emptystr(char ch);
char		*modstr_crt(t_mod *mod, int size, char ch);
const char	*error(const char *str);
char		*str_tostr(const char *start, const char *end, const char dev);
const char	*retres_fin(t_mod *mod, const char *s1, const char *s2, int pos);
//////////////////////////////////////NUMBER//////////////////////////////////
const char	*int_tostr(long n, const char *spec, const char *base);
const char	*uint_tostr(t_ul n, const char *spec, const char *base);
char		*uint_tostr_base(t_ul n, const char *base);
const char	*float_tostr(double n, const char *spec, const char *base, t_ui m);
const char	*hex_tostr(long n, const char *spec, const char *base, char *p_h);
char		*int_tostr_base(long n, const char *base);
char		*crtnumstr(long n, const char *base);
char		*crtnumstr_ul(t_ul n, const char *base);
char		*p_rec(t_ul n, const char *base, char *str, t_ui size);
void		swap_sign(char *str, char *num, int count);
t_ui		arrned_num(long n, const char *base);
t_ui		arrned_num_ul(t_ul n, const char *base);
const char	*intnum_mod(t_mod *mod, const char *str, char ch);
char		*modnstr_crt(t_mod *mod, int size);
//////////////////////////////////////ADRES////////////////////////////////////
const char	*addr_tostr(void *p, const char *spec, const char *base);
const char	*hex_mod(t_mod *mod, const char *str, char ch);
//////////////////////////////////////FIND SPEC////////////////////////////////
const char	*findstart(const char *spc);
size_t		count_spec(const char *str);
const char	*find_spec(const char *str);
//////////////////////////////////////SET FLAGS////////////////////////////////
t_mod		*setmod(const char *spc, const char *flags, const char *spec_o);
t_mod		*modfree(t_mod *mod);
int			isspec(const char *s, const char *spec_o);