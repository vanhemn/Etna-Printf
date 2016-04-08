/*
** echo.c for Projet_my_printf in /Users/vanhem_n/Documents/printf/echo.c
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Apr 4- 09:05:00 2016 VANHEMELRYCK nathan
** Last update thu Apr 7- 16:00:00 2016 VANHEMELRYCK nathan
*/

#include "my_printf.h"

void  my_putchar(char c)
{
  write (1, &c, 1);
}

void  my_putstr(char *str)
{
  int i;
  
  i = 0;
  while (*(str + i) != '\0')
    {
      my_putchar(*(str + i));
      ++i;
    }
}

int   my_strcmp(char *s1, char *s2)
{   
  int i;
  
  i= 0;
  while ((s1[i] != '\0') && (s2[i] != '\0'))
    {
      if (s1[i] < s2[i])
  return (-1);
      if (s1[i] > s2[i])
  return (1);
      i++;
    }
  /* double if sinon quand chaine differente alors bug */
  if (s1[i] < s2[i])
    return (-1);
  if (s1[i] > s2[i])
    return (1);
  return (0);
}

void    my_put_nbr(int n)
{
  if (n == -2147483648)
    {
      my_putstr("-2147483648");
    }
  else
    {
      if (n < 0)
	{
	  my_putchar('-');
	  n = -n;
	}
      if (n > 9)
	{
	  my_put_nbr(n / 10);
	}
      my_putchar((n % 10) + '0');
    }
}