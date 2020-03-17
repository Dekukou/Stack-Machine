/*
** ETNA PROJECT, 04/11/2019 by fayoll_a
** AbstractVM
** File description:
**      Stack Machine in C
*/

#include "../header/my_printf.h"
#include "../header/prototype.h"

int my_strcmp(char *s1, char *s2)
{
  int i = 0;
  
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    i++;
  return (s1[i] - s2[i]);
}

char* my_strchr(char* str, int c)
{
  while (*str) {
    if (*str == c)
      return (str);
    str = str + 1;
  }
  return (str);
}

char* my_strchr2(char* str, int c)
{
  char *tmp = str;
  
  while (*str) {
    if (*str == c)
      return (str);
    str = str + 1;
  }
  return (tmp);
}

char* my_strchr3(char* str, int c)
{
  char *tmp = str + 1;
  
  while (*str) {
    if (*str == c) {
      return (tmp);
    }
    str = tmp;
    tmp = tmp + 1;
  }
  return (str);
}

bool checkOperation(t_item *list)
{
  if (list == NULL || list->next == NULL) {
    my_printf("%s\n", "Not enough elements in the stack");
    return (false);
  }
  if (list->value == 0) {
    my_printf("%s\n", "You can't divide or modulo a number by 0.");
    return (false);
  }
  return (true);
}