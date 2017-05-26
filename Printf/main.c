/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:38:57 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/24 15:11:26 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

char g_lengths[8][3] = {"hh","h","ll","l","j","z","L","t"};
char g_types[14][2] = {"s","S","p","d","D","i","o","O","u","U","x","X","c","C"}	;

int		ft_strchr0(const char *str, int c)
{
	size_t	i;
	char	int_to_char;

	i = 0;
	int_to_char = c;
	while (i <= ft_strlen(str))
	{
		if (str[i] == int_to_char)
			return (i);
		i++;
	}
	return (-1);
}

t_param		*create_node(void)// maybe I don't need this?
{
	t_param *new;

	new = (t_param *)malloc(sizeof(t_param));
	new->parameter = 0;
	new->flag = 0;
	new->width = -1;
	new->precision = -1;
	new->length = -1;
	new->type = -1;
	new->extra = 0;
	return (new);
}

void	ft_printf(char *fmt, ...)
{
	va_list ap, ap2;
	int d;
	char c, *s;
	int i = 0;
	char *work_str;
	t_param *a;
	int	start;

	va_start(ap, fmt);
	//printf("\nWhole length=%zu, \"%s\"", ft_strlen(fmt), fmt);

	start = ft_strchr0(fmt, '%');
	ft_putstr(ft_strsub(fmt, 0, start));
	while (fmt[start])
	{
	//	printf("\nA\n");
	//	printf("HERE: %i\n", start);

		work_str = get_work_str(&fmt[start]);
		a = parse(work_str);
		//printf("\n------%i.--------(start=%i) \"%s\"\n", i, start, work_str);
	  //printf("\nparameter=%i\nflag=%s\nwidth=%i\nprecision=%i\nlength=%s\ntype=%s\nextra=%s\nlen of extra=%zu\n", a->parameter, a->flag, a->width, a->precision, g_lengths[a->length], g_types[a->type], a->extra, ft_strlen(a->extra));

		work_var(a, ap);
		start = start + ft_strlen(work_str);
		//printf("All_len=%zu\nstart=%i\n",ft_strlen(fmt), start);
		i++;

	}

	//	va_copy(ap2, ap);
	/*	while (fmt[i])
		{
		if(fmt[i] == 'd')
		{
		d = va_arg(ap, int);
		printf("%d\n", d);
		}
		i++;
		}*/
}

int		main(void)
{
	char a[20] = "HEllo";
 	int b = 5;

//	ft_printf("HEllo%1$#1.56zi,___%2$i,!!!HEllo%1$lli", b, 14);
	//ft_printf("%00i\n", 5);
//	printf("Example:%i\n", atoi("s"));
printf("Real thing:%p\nX=%#x\n", &b, &b);
	ft_printf("\nStart_delta!%s!%d\n!My pointer:%p\n", "Hello", 5, &b);
//	ft_printf("!%10li\n", b);

//	printf("%0o\n",b );
//	printf("res= %1$010.2f\n", 12.50);
//
//	printf("%3$li  %2$#x\n; %1$d %1$#x", 16, 17, b);

	return (0);
}
