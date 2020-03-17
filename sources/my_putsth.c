/*
** ETNA PROJECT, 04/11/2019 by puig_j
** AbstractVM
** File description:
**      Stack Machine in C
*/

#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}

int my_strlen(char* str)
{
  int i = 0;
  
  while (str[i] != '\0')
    i++;
  return (i);
}

void my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_putnbr_base(int n, char *base)
{
  int	nb;
  int	result;
  int	div = my_strlen(base);
  
  if (n < 0) {
    my_putchar('-');
    n = -n;
  }
  result = n % div;
  nb = (n - result) / div;
  if (nb != 0)
    my_putnbr_base(nb, base);
  my_putchar(base[result]);
  return (0);
}

int my_putnbr_uns(unsigned int n)
{
  unsigned int nb;
  
  if (n >= 10) {
    nb = n % 10;
    n = n / 10;
    my_putnbr_uns(n);
    my_putchar("0123456789"[nb]);
  }
  else 
    my_putchar("0123456789"[n]);
  return (0);
}
