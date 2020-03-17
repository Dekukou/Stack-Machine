/*
** ETNA PROJECT, 04/11/2019 by puig_j
** AbstractVM
** File description:
**      Stack Machine in C
*/

#include "../header/my_printf.h"

int my_printf(const char *parse, ...)
{
  va_list list;
  int i = 0;
  
  va_start(list, parse);
  while (parse[i] != '\0') {
    if (parse[i] != '%') {
      my_putchar(parse[i]);
    } else {
    	switch(parse[i + 1]) {
    		case 'd' :
			case 'i' :
				my_putnbr(va_arg(list, int));
				break;
			case 'c' :
				my_putchar(va_arg(list, int));
				break;
			case 's' :
				my_putstr(va_arg(list, char*));
				break;
			case 'o' :
				my_putnbr_base(va_arg(list, int), "01234567");
				break;
			case 'x' :
				my_putnbr_base(va_arg(list, int), "0123456789abcdef");
				break;
			case 'X' :
				my_putnbr_base(va_arg(list, int), "0123456789ABCDEF");
				break;
			case 'u' :
				my_putnbr_uns(va_arg(list, int));
				break;
			case 'b' :
				my_putnbr_base(va_arg(list, int), "01");
				break;
			case 'f' :
			  my_printfloat(va_arg(list, double));
			  break;
			default :
				my_putchar('%');
		}
		++i;
    }
    ++i;
  }
  va_end(list);
  return (0);
}