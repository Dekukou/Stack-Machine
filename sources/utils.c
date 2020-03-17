/*
** ETNA PROJECT, 04/11/2019 by puig_j
** AbstractVM
** File description:
**      Stack Machine in C
*/

#include "../header/my_printf.h"
#include "../header/prototype.h"

int my_getnbr(char *str)
{
  int n = 0;
  int sign = 1;

  while (*str == '-') {
    if (*str == '-')
      sign = sign * -1;
    str++;
  }
  while (*str >= '0' && *str <= '9') {
    n = n * 10;
    n = n + (*str - '0');
    str++;
  }
  return (sign * n);
}

double my_getfloat(char *str)
{
  int sign = 1;
  double i = 10;
  double n = (double) my_getnbr(str);

  if (n < 0) {
    n = n * -1;
    sign = sign * -1;
  }
  while (*str >= '0' && *str <= '9')
    str++;
  if (*str == '.') {
    while (str[1] >= '0' && str[1] <= '9') {
      n = n + (str[1] - '0') / i;
      i = i * 10;
      str++;
    }
  }
  return (n * sign);
}

char *my_strcpy(char *dest, char *src)
{
  int i = 0;

  while (src[i] != '\0') {
    dest[i] =  src[i];
    i++;
    if (src[i] == '\0')
      dest[i] = '\0';
  }
  return (dest);
}

char *my_strrev(char *str)
{
  int n = my_strlen(str) - 1;
  char *tmp = malloc((n + 1) * sizeof(char));
  int i = 0;

  while (n >= 0) {
    tmp[i] = str[n];
    i++;
    n--;
  }
  tmp[i] = '\0';
  return tmp;
}

char *checkStr(char *str)
{
  int i = 0;
  int j = 0;
  char *tmp = malloc(my_strlen(str) + 1 + 1);

  while(str[i] != '\0') {
    if (str[i] == ';')
      while(str[i] != '\0')
        i++;
    if ((str[i - 1] != ' ' && str[i - 1] != '\t') || (str[i] != ' ' && str[i] != '\t'))
      if ((str[i] != ' ' || str[i] != '\t'))
        if (i != 0 || (str[i] != ' ' && str[i] != '\t')) {
          tmp[j] = str[i];
          j++;
        }
    i++;
  }
  tmp[j] = '\0';
  return (tmp);
}
