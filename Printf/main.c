/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:38:57 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/15 16:02:08 by adosiak          ###   ########.fr       */
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
//	va_copy(ap2, ap);
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

//	foo("%d", b);
//	printf("%0o\n",b );
//	printf("res= %1$010.2f\n", 12.50);
//
	printf("%3$lli  %2$#x\n; %1$d %1$#x", 16, 17, 15);

	return (0);
}

