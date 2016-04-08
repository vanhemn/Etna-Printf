/*
** echo2.c for Projet_my_printf in /Users/vanhem_n/Documents/printf/echo2.c
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Apr 4- 17:10:00 2016 VANHEMELRYCK nathan
** Last update thu Apr 7- 16:00:00 2016 VANHEMELRYCK nathan
*/

#include "my_printf.h"

int my_strlen(char *str)
{
  int i;
  
  i = 0;
  while (*(str + i) != '\0')
    {
      ++i;
    }
  return (i);
}

void    my_putnbr_base(int nb, char *base)
{
  int   op;
  int   result;
  int   base_long;
  
  base_long = my_strlen(base);
  if (nb < 0)
    {
      nb = -nb;
    }
  op = 1;
  while ((nb / op) >= base_long)
    op *= base_long;
  while (op > 0)
    {
      result = (nb / op) % base_long;
      my_putchar(base[result]);
      op /= base_long;
    }
}

int   my_put_nbr_unsigned(long unsigned int nb, char *base)
{
  int   base_long;
  int   i;
  int   result;
  
  result = 0;
  base_long = my_strlen(base);
  i = nb % base_long;
  nb /= base_long;
  if (nb > 0)
    result += my_put_nbr_unsigned(nb, base);
  my_putchar(base[i]);
  result++;
  return (result);
}
