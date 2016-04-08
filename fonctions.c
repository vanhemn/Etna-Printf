/*
** function.c for Projet_my_printf in /Users/vanhem_n/Documents/printf/function.c
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Apr 4- 09:05:00 2016 VANHEMELRYCK nathan
** Last update thu Apr 7- 15:05:10 2016 VANHEMELRYCK nathan
*/

#include "my_printf.h"

/* Fonction Int */
void        opt_i(void* aff){
  my_put_nbr((intptr_t)aff);
}

/* Fonction Char* */
void        opt_s(void* aff){
  my_putstr((char *)aff);
}

/* Fonction Char */
void        opt_c(void* aff){
  my_putchar((intptr_t)aff);
}

/* Fonction base 8 */
void        opt_o(void* aff){
  char* base;
  
  base = "01234567";
  my_putnbr_base((intptr_t)aff, base);
}
