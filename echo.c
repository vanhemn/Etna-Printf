/*
** echo.c for Projet_my_printf in /Users/vanhem_n/Documents/printf/echo.c
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** Started on  Mon Apr 4- 09:05:00 2016 VANHEMELRYCK nathan
** Last update thu Apr 7- 16:00:00 2016 VANHEMELRYCK nathan
*/

#include "include.h"

void	my_putchar(char c)
{
  write (1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

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

int	my_strlen(char *str)
{
  int	i;

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

int		my_put_nbr_unsigned(long unsigned int nb, char *base)
{
  int		base_long;
  int		i;
  int		result;

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