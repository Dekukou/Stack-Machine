/*
** ETNA PROJECT, 04/11/2019 by fayoll_a
** AbstractVM
** File description:
**      Stack Machine in C
*/

#include "../header/pile.h"
#include "../header/my_printf.h"
#include "../header/prototype.h"

int my_putnbr(int nb)
{
  if (nb < 0) {
    if (nb == -2147483648) {
      my_putchar('-');
      my_putchar('2');
      my_putnbr(147483648);
    } else {
      my_putchar('-');
      my_putnbr(-nb);
    }
  } else {
    if (nb > 9)
      my_putnbr(nb / 10);
    my_putchar(nb % 10 + 48);
  }
  return (0);
}

int my_printint(double nb)
{
  my_putnbr((int)nb);
  return (0);
}

double my_round(double var) 
{ 
  double value = (int)(var * 100 + .5); 
  return (double)value / 100; 
} 

void my_printfloat(double nb)
{
  int integer = (int)(nb / 1);
  int decimal = (int)(my_round(( nb - integer) * 1000000));

  if (integer < 0)
    decimal = decimal * (-1);
  my_putnbr(integer);
  my_putchar('.');
  my_putnbr(decimal);
}

int my_printvalue(double nb, char *type)
{
  if (my_strcmp(type, "int8") == 0 || my_strcmp(type, "int16") == 0 || my_strcmp(type, "int32") == 0)
    my_printint(nb);
  else
    my_printfloat(nb);
  return (0);
}