/*
** ETNA PROJECT, 04/11/2019 by puig_j
** AbstractVM
** File description:
**      Stack Machine in C
*/

#include "../header/pile.h"
#include "../header/my_printf.h"
#include "../header/prototype.h"

void print_item(t_item *list)
{
  if (list == NULL)
    my_printf("%s\n", "Not enough elements in the stack");
  else {
    if (my_strcmp(list->type, "int8") == 0 && list->value >= 0 && list->value <= 127)
      my_printf("%c\n", (int) list->value);
    else
      my_printf("Your int is not supported\n");
  }
}

void dump_item(t_item *list)
{
  t_item *previous = list;
  
  while(previous != NULL) {
    my_printvalue(previous->value, previous->type);
    my_printf("\n");
    previous = previous->next;
  }
}

double check_value(double value, char *type)
{
  if (my_strcmp(type, "int8") == 0 && value >= -128 && value <= 127)
    return (value);
  if (my_strcmp(type, "int16") == 0 && value >= -32768 && value <= 32767)
    return (value);
  if (my_strcmp(type, "int32") == 0 && value >= (-2147483647 - 1) && value <= 2147483647)
    return (value);
  if (my_strcmp(type, "float") == 0 || my_strcmp(type, "double") == 0)
    return (value);
  my_printvalue(value, type);
  my_printf(" not correspond to %s\n", type);
  return (0);
}

char *select_type(char *first_type, char *second_type)
{
  if (my_strcmp(first_type, "double") == 0 || my_strcmp(second_type, "double") == 0) {
    return ("double");
  } else if (my_strcmp(first_type, "float") == 0 || my_strcmp(second_type, "float") == 0) {
    return ("float");
  } else if (my_strcmp(first_type, "int32") == 0 || my_strcmp(second_type, "int32") == 0) {
    return ("int32");
  } else if (my_strcmp(first_type, "int16") == 0 || my_strcmp(second_type, "int16") == 0) {
    return ("int16");
  } else {
    return ("int8");
  }
}

void assert(t_item *list, double value, char *type)
{
  if (list->value == value && my_strcmp(list->type, type) == 0)
    my_printf("The value is good\n");
  else
    my_printf("The value is KO\n");
}