/*
** ETNA PROJECT, 04/11/2019 by puig_j
** AbstractVM
** File description:
**      Stack Machine in C
*/

#include <stdbool.h>
#include "../header/pile.h"
#include "../header/my_printf.h"
#include "../header/prototype.h"

char *stringArray(int *i, char *buf)
{
  int k = 0;
  char *str = malloc((129) * sizeof(char));

  while(buf[*i] != '\n') {
    str[k++] = buf[*i];
    *i = *i + 1;
  }
  str[k] = '\0';
  return (checkStr(str));
}

char **readFile(int fd)
{
  int i = 0;
  int j = 0;
  char *tmp;
  char buf[1024];
  int size = read(fd, buf, 1023);
  char **arr = malloc(20 * sizeof(char*));
  
  buf[size] = 0;
  while(buf[i] != '\0') {
    tmp = stringArray(&i, buf);
    if (my_strcmp(tmp, "\0")) {
      arr[j] = malloc(20 * sizeof(char));
      arr[j] = tmp;
      j++;
    }
    i++;
  }
  return (arr);
}

bool checkExit(char **arr)
{
  int n = 0;

  while(arr[n] != '\0') {
    if (my_strcmp(arr[n], "exit") == 0)
      return (true);
    n++;
  }
  return (false);
}

bool checkFile2(char *argv[], int fd)
{
  char **arr;
  bool exit = false;

  if (my_strcmp(my_strchr(argv[1], '.'),".avm") == 0) {
    my_printf("----- Your file is okay -----\n");
    arr = readFile(fd);
    exit = checkExit(arr);
    close(fd);
    if (exit == false)
      return (exit);
    parser(arr);
  } else
  my_printf("----- Your file doesn't have the good extension -----\n");
  return (exit);
}

bool checkFile(int argc, char *argv[])
{
  int fd;
  bool exit = false;

  if ( argc != 2 )
    my_printf("Usage:\n\t./abstractvm path/to/program.avm\n");
  else {
    fd = open(argv[1], O_RDONLY);
    if( fd != -1 )
      exit = checkFile2(argv, fd);
    else 
      my_printf("----- Your file don't exist -----\n");
  }
  return (exit);
}