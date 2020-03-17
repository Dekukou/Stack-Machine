/*
** ETNA PROJECT, 04/11/2019 by fayoll_a
** AbstractVM
** File description:
**      Stack Machine in C
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include "pile.h"

int my_getnbr(char *str);
double my_getfloat(char *s);
char *my_strcpy(char *dest, char *src);
char *my_strrev(char *str);
char *checkStr(char *str);

double check_value(double value, char *type);
char *select_type(char *first_type, char *second_type);

void print_item(t_item *list);
void assert(t_item *list, double value, char *type);
void dump_item(t_item *list);

bool checkOperation(t_item *list);
bool checkFile( int argc, char *argv[]);
bool parser(char **arr);

t_item *add_item(t_item *list, double value, char *type);
t_item *delete_item(t_item *list, double value);
t_item *deleteFirst_item(t_item *list);

t_item *addition_item(t_item *list);
t_item *substraction_item(t_item *list);
t_item *multiply_item(t_item *list);
t_item *divide_item(t_item *list);
t_item *modulo_item(t_item *list);

t_item *interpreter(char *str, char *str2, t_item *list);
t_item *interpreter2(char *str, char *str2, t_item *list);