/*
** ETNA PROJECT, 04/11/2019 by puig_j
** AbstractVM
** File description:
**      Stack Machine in C
*/

#include <stdlib.h>
#include "../header/pile.h"
#include "../header/my_printf.h"
#include "../header/prototype.h"

t_item *add_item( t_item *list, double value, char *type )
{
  t_item *node = malloc(sizeof(*node));
  double tmp = value;
  
  if (node == NULL)
    return (0);
  if (check_value(value, type) == tmp) {
    node->next = list;
    node->value = value;
    node->type = type; 
  } else {
    my_printf("Error during add item\n");
    return (list);
  }
  return (node);
}

t_item *delete_item(t_item *list, double value)
{
  t_item *previous = list;
  t_item *tmp = previous->next;
  
  if (list == NULL)
    return (list);
  if (previous->value == value) {
    return (deleteFirst_item(list));
  }
  while(tmp != NULL) {
    if (tmp->value == value) {
      previous->next = tmp->next;
      free(tmp);
      return (list);
    }
    previous = tmp;
    tmp = tmp->next;
  }
  return (list);
}

t_item *deleteFirst_item(t_item *list)
{
  t_item *previous;

  if (list == NULL)
    return (list);
  previous = list;
  list = previous->next;
  free(previous);
  return (list);
}