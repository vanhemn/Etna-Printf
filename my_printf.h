/*
** include.h for Projet_my_printf in /Users/vanhem_n/Documents/printf/include.h
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Apr 4- 09:20:00 2016 VANHEMELRYCK nathan
** Last update thu Apr 7- 16:55:02 2016 VANHEMELRYCK nathan
*/

#ifndef __MY_PRINTF_H__
#define __MY_PRINTF_H__

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

typedef struct s_opt
{
	char key;
  	void (*pf)(void*);
} a_opt;


int 	my_printf(char *, ...);
void 	opt_i(void* aff);
void 	opt_c(void* aff);
void 	opt_u(void* aff);
void 	opt_X(void* aff);
void 	opt_x(void* aff);
void 	opt_s(void* aff);
void 	opt_o(void* aff);
void	my_putchar(char c);
void	my_putstr(char *str);
int   	my_strcmp(char *s1, char *s2);
void    my_put_nbr(int n);
void    my_putnbr_base(int nb, char *base);
int		my_put_nbr_unsigned(long unsigned int nb, char *base);


#endif