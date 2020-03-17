/*
** ETNA PROJECT, 04/11/2019 by puig_j
** AbstractVM
** File description:
**      Stack Machine in C
*/

#include "header/pile.h"
#include "header/prototype.h"
#include "header/my_printf.h"

int main(int argc, char *argv[])
{
  if(checkFile(argc, argv) == false)
    my_printf("Your file does not contain the \"exit\" function\n");
}
