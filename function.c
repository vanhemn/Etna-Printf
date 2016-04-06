/*
** function.c for Projet_my_printf in /Users/vanhem_n/Documents/printf/function.c
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Apr 4- 09:05:00 2016 VANHEMELRYCK nathan
** Last update thu Apr 7- 15:05:10 2016 VANHEMELRYCK nathan
*/

#include "include.h"

/* Fonction Int */
void 		opt_i(void* aff){
	my_put_nbr((int)aff);
}

/* Fonction Char* */
void 		opt_s(void* aff){
	my_putstr((char *)aff);
}

/* Fonction Char */
void 		opt_c(void* aff){
	my_putchar((char)aff);
}

/* Fonction base 8 */
void 		opt_o(void* aff){
	char* base;

	base = "01234567";
	my_putnbr_base((int)aff, base);
}

/* Fonction unsigned */
void 		opt_u(void* aff){
	char* base;

	base = "0123456789";
	my_put_nbr_unsigned((long unsigned int)aff, base);
}

/* Fonction hexa minuscule */
void 		opt_X(void* aff){
	char* base;

	base = "0123456789ABCDEF";
	my_putnbr_base((int)aff, base);
}

/* Fonction hexa Majuscule */
void 		opt_x(void* aff){
	char* base;

	base = "0123456789abcdef";
	my_putnbr_base((int)aff, base);
}


