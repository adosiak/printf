/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:38:57 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/11 17:26:23 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	foo(char *fmt, ...)
{
	va_list ap, ap2;
	int d;
	char c, *s;
	int i = 0;

	va_start(ap, fmt);
	va_copy(ap2, ap);
	while (fmt[i])
	{
		if(fmt[i] == 'd')
		{
			d = va_arg(ap, int);
			printf("%d\n", d);
		}
		i++;
	}
}

int		main(void)
{
	char a[20] = "HEllo";
	int b = 5;
//	int res = printf("!%10lli\n", b);

	foo("%d", b);
//	printf("%0o\n",b );
//	printf("res= %i", res);

	return (0);
}

