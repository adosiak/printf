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
#include <limits.h>


int		main(void)
{
	char a[20] = "";
 	int b = 10;
	int *a1 = &b;
	float f = 10.0202;
	char *aa = NULL;
//----%s----
//printf("MY:%i\n", ft_printf("% d string. gg!", "this", "string"));
//printf("cr:%i\n", printf("% d string. gg!", "this", "string"));


//---%d-----
	//printf("MY:%i\n", ft_printf("% 0    d", b));
	//printf("cr:%i\n", printf("% 0    d", b));

	/*printf("MY:%i\n", ft_printf("% d", 0));
	printf("cr:%i\n", printf("% d", 0));*/

//	ft_printf("%5.2s is a string", "");

//----%U-----FIX THIS
//printf("my:%d\n",ft_printf("\n%U", ULONG_MAX));
//printf("cr:%d\n", printf("\n%U", ULONG_MAX));

//printf("%d %d %d\n", sizeof(int), sizeof(long), sizeof(long long));
	//printf("\nMY:%i\n", ft_printf("%5.2s is a string", ""));
	//printf("\ncr:%i\n", printf("%5.2s is a string", ""));
// ---%u------
	//printf("MY:%i\n", ft_printf("%%u:%-0u\n", b));
//	printf("cr:%i\n", printf("%%u:%-0u\n", b));
	 //---%o------
		//printf("MY:%i\n", ft_printf("%10.5d", 4242));
	//	printf("cr:%i\n", printf("%10.5d", 4242));

		printf("MY:%i\n", ft_printf("%0+5d", -42));
		printf("cr:%i\n", printf("%0+5d", -42));




		//---%x------
 		/*printf("MY:%i\n", ft_printf("%%x:@moulitest: %#.x %#.0x", 0, 0));
 		printf("cr:%i\n", printf("%%x:@moulitest: %#.x %#.0x", 0, 0));
*/
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
