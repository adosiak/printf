#include "libft.h"
#include "header.h"

int ft_putfree(char *str)
{
  int len;
  len = ft_strlen(str);
  ft_putstr(str);
  free(str);
  return (len);
}
