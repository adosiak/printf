#include "header.h"
#include "libft.h"

void work_var(t_param *a, va_list ap)
{
  if (a->type == 0)
    type_s(a, ap);
  if (a->type == 2)
    type_p(a, ap);
  if (a->type == 3)
    type_d(a, ap);
  ft_putstr(a->extra);
}

void type_s(t_param *a, va_list ap)
{
  char *str;
  str = va_arg(ap, char *);
  ft_putstr(str);
}

void type_d(t_param *a, va_list ap)
{
  int d;
  d = va_arg(ap, int);
  ft_putnbr(d);
}
void type_p(t_param *a, va_list ap)
{
  size_t p;
  p = va_arg(ap, size_t);
  //work on ft_itoa_base(change int to unsingned long long?);
  ft_putstr(ft_itoa_base(p, 16));
//  printf("###\n");
  //printf("\nCorrect:%p\n", &p);

}
