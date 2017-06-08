/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:09:12 by adosiak           #+#    #+#             */
/*   Updated: 2017/06/08 14:09:16 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

void handle_star(t_param *a, va_list ap)
{
  int width;
  int precision;
  //printf("1.width=%i\n", a->width);

  if (a->width == -2)
    {
      width = va_arg(ap, int);
      if (width < 0)
      {
        a->flag.n_flg++;
        a->width = width * (-1);
      }
      else
        a->width = width;
    }
  if (a->precision == -2)
  {
    a->precision = va_arg(ap, int);
  //  printf("pres=%i", a->precision);
    if (a->precision < 0)
      a->precision = a->precision * (-1);
  //  printf("pres=%i", a->precision);

  }

}
