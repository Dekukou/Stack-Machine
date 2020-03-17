/*
** ETNA PROJECT, 04/11/2019 by fayoll_a
** AbstractVM
** File description:
**      Stack Machine in C
*/

#include <stdbool.h>
#include "../header/pile.h"
#include "../header/my_printf.h"
#include "../header/prototype.h"

t_item *interpreter2(char *str, char *str2, t_item *list)
{
  str = my_strrev(checkStr(my_strrev(str)));
  char *all = checkStr(my_strchr(str2, ' '));
  char *type = my_strrev(my_strchr3(my_strrev(all), '('));
  double value = my_getfloat(my_strrev(my_strchr3(my_strrev(my_strchr3(all, '(')), ')')));

  if (!my_strcmp(str, "push"))
    list = add_item(list, value, type);
  else if(!my_strcmp(str, "assert"))
    assert(list, value, type);
  else if(!my_strcmp(str, "print"))
    print_item(list);
  else
    my_printf("The %s%s", str, " function is not part of the program.\n");
  return (list);
}

t_item *interpreter(char *str, char *str2, t_item *list)
{
  if (!my_strcmp(str, "add"))
    list = addition_item(list);
  else if (!my_strcmp(str, "sub"))
    list = substraction_item(list);
  else if (!my_strcmp(str, "mul"))
    list = multiply_item(list);
  else if (!my_strcmp(str, "div"))
    list = divide_item(list);
  else if (!my_strcmp(str, "mod"))
    list = modulo_item(list);
  else if (!my_strcmp(str, "pop"))
    list = deleteFirst_item(list);
  else if (!my_strcmp(str, "dump"))
    dump_item(list);
  else
    list = interpreter2(str, str2, list);
  return (list);
}

bool parser(char **arr)
{
  int n = 0;
  char *tmp;
  t_item *list = NULL;

  while(arr[n] != '\0') {
    tmp = my_strrev(my_strchr2(my_strrev(arr[n]), ' '));
    if (!my_strcmp(tmp, "exit")) 
      return (true);
    list = interpreter(tmp, arr[n], list);
    n++;
  }
  return (false);
}
