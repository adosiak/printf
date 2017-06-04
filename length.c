
# include "header.h"
# include "libft.h"

unsigned long long get_uox(t_param *a, va_list ap)
{
   if (a->type == 9)
      return (va_arg(ap, unsigned long));
    else if (a->length == 0)
      return((unsigned char)va_arg(ap, unsigned int));
    else if (a->length == 1)
      return((unsigned short)va_arg(ap, unsigned int));
    else if (a->length == 2)
      return(va_arg(ap, unsigned long));
    else if (a->length == 3)
      return(va_arg(ap, unsigned long long));
    else if (a->length == 4)
      return(va_arg(ap, uintmax_t));
    else if (a->length == 5)
        return(va_arg(ap, size_t));
    return (va_arg(ap, unsigned int));
}

long long get_di(t_param *a, va_list ap)
{
    if (a->length == 0)
      return((char)va_arg(ap, int));
    else if (a->length == 1)
      return((short)va_arg(ap, int));
    else if (a->length == 2 || a->type == 4)
      return(va_arg(ap, long));
    else if (a->length == 3)
      return(va_arg(ap, long long));
    else if (a->length == 4)
      return(va_arg(ap, intmax_t));
    else if (a->length == 5)
        return(va_arg(ap, size_t));
    return (va_arg(ap, int));
}
