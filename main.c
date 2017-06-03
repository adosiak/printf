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
	char a[20] = "";
 	int b = 10;
	int *a1 = &b;
	float f = 10.0202;
	char *aa = NULL;
//----%s----
//	printf("1.res=%i\n", ft_printf("   %-5%"));
	//printf("\n---\n");
	//printf("\n2.res=%i\n", printf("%#08x", 42));
//---%d-----
/*	printf("MY:%i\n", ft_printf("% 0    d", b));
	printf("cr:%i\n", printf("% 0 d", b));*/

	printf("MY:%i\n", ft_printf("%-3.6sHey", a));
	printf("cr:%i\n", printf("%-3.6sHey", a));
// ---%u------
	//printf("MY:%i\n", ft_printf("%%u:%-0u\n", b));
//	printf("cr:%i\n", printf("%%u:%-0u\n", b));
	 //---%o------
		/*printf("MY:%i\n", ft_printf("%%o:%.0o\n", b));
		printf("cr:%i\n", printf("%%o:%.0o\n", b));*/



		//---%x------
// 		printf("MY:%i\n", ft_printf("%%x:%0#8x\n", 42));
 //		printf("cr:%i\n", printf("%%x:%0#8x\n", 42));

		//---%p------
	/*printf("MY:%i\n", ft_printf("%%p:%p\n", a1));
	printf("cr:%i\n", printf("%%p:%1p\n", a1));*/

	//---%f------
//printf("MY:%i\n", ft_printf("%%p:%p\n", a1));
//printf("cr:%i\n", printf("%%f:%-20.p\n", a1));

	//---%c----
	/*printf("MY:%i\n", ft_printf("%%c:%-c\n", a[0]));
	printf("cr:%i\n", printf("%%c:%-c\n", a[0]));*/
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
