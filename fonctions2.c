/*
** function2.c for Projet_my_printf in /Users/vanhem_n/Documents/printf/function2.c
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Apr 4- 09:10:00 2016 VANHEMELRYCK nathan
** Last update thu Apr 7- 15:05:10 2016 VANHEMELRYCK nathan
*/

#include "my_printf.h"

/* Fonction unsigned */
void        opt_u(void* aff){
  char* base;
  
  base = "0123456789";
  my_put_nbr_unsigned((long unsigned int)aff, base);
}

/* Fonction hexa minuscule */
void        opt_X(void* aff){
  char* base;
  
  base = "0123456789ABCDEF";
  my_putnbr_base((intptr_t)aff, base);
}

/* Fonction hexa Majuscule */
void        opt_x(void* aff){
  char* base;
  
  base = "0123456789abcdef";
  my_putnbr_base((intptr_t)aff, base);
}
