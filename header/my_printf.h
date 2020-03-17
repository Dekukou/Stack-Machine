/*
** ETNA PROJECT, 04/11/2019 by puig_j
** AbstractVM
** File description:
**      Stack Machine in C
*/

#include <unistd.h>
#include <stdarg.h>

int my_printf(const char *parse, ...);

void my_putstr(char *str);
void my_putchar(char c);
void my_printfloat(double nb);

int my_strlen(char* str);
int my_putnbr_base(int n, char *base);
int my_putnbr_uns(unsigned int n);
int my_putnbr(int b);
int my_strcmp(char *s1, char *s2);
int my_printvalue(double nb, char *type);

double my_round(double var);

char* my_strchr(char* str, int c);
char* my_strchr2(char* str, int c);
char* my_strchr3(char* str, int c);
