/*
** ETNA PROJECT, 04/11/2019 by fayoll_a
** AbstractVM
** File description:
**      Stack Machine in C
*/

#include "../header/pile.h"
#include "../header/my_printf.h"
#include "../header/prototype.h"

t_item *addition_item(t_item *list)
{
  char *type;
  double test;
  t_item *first_item = list;
  t_item *second_item = list->next;
  
  if (list == NULL || list->next == NULL) {
    my_printf("%s\n", "Not enough elements in the stack");
    return (list);
  }
  test = first_item->value + second_item->value;
  type = select_type(first_item->type, second_item->type);

  list = delete_item(list, first_item->value);
  list = delete_item(list, second_item->value);
  list = add_item(list, test, type);
  return (list);
}

t_item *substraction_item(t_item *list)
{
  char *type;
  double test;
  t_item *first_item = list;
  t_item *second_item = list->next;
  
  if (list == NULL || list->next == NULL) {
    my_printf("%s\n", "Not enough elements in the stack");
    return (list);
  }
  test = second_item->value - first_item->value;
  type = select_type(first_item->type, second_item->type);
  list = delete_item(list, first_item->value);
  list = delete_item(list, second_item->value);
  list = add_item(list, test, type);
  return (list);
}

t_item *multiply_item(t_item *list)
{
  char *type;
  double test;
  t_item *first_item = list;
  t_item *second_item = list->next;
  
  if (list == NULL || list->next == NULL) {
    my_printf("%s\n", "Not enough elements in the stack");
    return (list);
  }
  test = my_round(second_item->value * first_item->value);
  type = select_type(first_item->type, second_item->type);
  list = delete_item(list, first_item->value);
  list = delete_item(list, second_item->value);
  list = add_item(list, test, type);
  return (list);
}

t_item *divide_item(t_item *list)
{
  char *type;
  double test;
  t_item *first_item = list;
  t_item *second_item = list->next;
  
  if (checkOperation(list))
    return (list);
  test = second_item->value / first_item->value;
  type = select_type(first_item->type, second_item->type);
  list = delete_item(list, first_item->value);
  list = delete_item(list, second_item->value);
  list = add_item(list, test, type);
  return (list);
}

t_item *modulo_item(t_item *list)
{
  char *type;
  double test;
  t_item *first_item = list;
  t_item *second_item = list->next;
  double a = second_item->value;
  double b = first_item->value;
  
  if (checkOperation(list))
    return (list);
  a = second_item->value / first_item->value;
  b = (int) a * first_item->value;
  test = second_item->value - b;

  type = select_type(first_item->type, second_item->type);
  list = delete_item(list, first_item->value);
  list = delete_item(list, second_item->value);
  list = add_item(list, test, type);
  return (list);
}