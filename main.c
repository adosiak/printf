/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:38:57 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/26 19:04:33 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/header.h"


int		main(void)
{
	char a[20] = "HEllo";
 	int b = -5000;
	int *a1 = &b;

	/*printf("1.res=%i\n", ft_printf("I'm printing this:%-13.5s\n", a));
	printf("2.res=%i\n", printf("I'm printing this:%-13.5s\n", a));*/

	printf("MY:%i\n", ft_printf("%%d:%-8d\n", b));
	printf("cr:%i\n", printf("%%d:%-8d\n", b));

/*	ft_printf("Correct:%%%ls\n", &b);
	printf("Correct:%%%ls\n", a);*/

//	printf("Correct:%%%.1s\n", (char *)&b);
//
//
/*	ft_printf("1.HEllo%1$#1.5zi,_%%__%2$i,!!!HEllo%1$lli\n", b, 14);
	printf("2.HEllo%1$#1.5zi,_%%__%2$i,!!!HEllo%1$i", b, 14);*/
	//ft_printf("%00i\n", 5);
//	printf("Example:%i\n", atoi("s"));
/*printf("Real thing:%p\nX=%#x\n", &b, &b);
	ft_printf("\nStart_delta!%s!%d\n!My pointer:%p\n", "Hello", 5, &b);*/
//	ft_printf("!%10li\n", b);

//	printf("%0o\n",b );
//	printf("res= %1$010.2f\n", 12.50);
//
//	printf("%3$li  %2$#x\n; %1$d %1$#x", 16, 17, b);

	return (0);
}
