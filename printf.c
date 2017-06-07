
#include "libft.h"
#include "header.h"

char g_lengths[8][3] = {"hh","h","l","ll","j","z","L","t"};
char g_types[14][2] = {"s","S","p","d","D","i","o","O","u","U","x","X","c","C"}	;

int		ft_strchr0(const char *str, int pos, int c)
{
	size_t	i;
	char	int_to_char;

	i = pos;
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
	new->flag.is = 0;
	new->flag.p_flg = 0;
	new->flag.n_flg = 0;
	new->flag.h_flg = 0;
	new->flag.z_flg = 0;
	new->width = -1;
	new->precision = -1;
	new->length = -1;
	new->type = -1;
	new->extra = 0;
	new->spaces = 0;
	return (new);
}

int		ft_printf(char *fmt, ...)
{
	va_list ap;
	int i = 0;
	char *work_str;
	t_param *a;
	int	start;
	int	len_work_str;
	int res;

	va_start(ap, fmt);
	//printf("\nWhole length=%zu, \"%s\"", ft_strlen(fmt), fmt);

	start = ft_strchr0(fmt, 0, '%');
	if (start == -1)
	{
		ft_putstr(fmt);
		return (ft_strlen(fmt));
	}
	ft_putfree(ft_strsub(fmt, 0, start));
	res = start;
	while (fmt[start])
	{
			//printf("\nA\n");
		//	printf("start in printf: %i\n", start);

		work_str = get_work_str(&fmt[start]);
		len_work_str = ft_strlen(work_str);

		a = parse(work_str);
		free(work_str);
		/*printf("\n------%i.--------(start=%i) \"%s\"\n", i, start, work_str);
		printf("\nflag.z=%i\nflag.n=%i\nflag.p=%i\nflag.h=%i\n", a->flag.z_flg, a->flag.n_flg,a->flag.p_flg,a->flag.h_flg);
		printf("\nparameter=%i\nwidth=%i\nprecision=%i\nlength=%s\ntype=%s\nextra=%s\nlen of extra=%zu\nspaces=%i\n", a->parameter, a->width, a->precision, g_lengths[a->length], g_types[a->type], a->extra, ft_strlen(a->extra), a->spaces);
*/
	 //printf("\n1.res in printf:%d\n", res);
		res += work_var(a, ap);
		//if (a->extra)
		free(a->extra);
		free(a);
		//printf("\n2.res in printf:%d\n", res);
		start = start + len_work_str;//+ ft_strlen(work_str);
		//printf("All_len=%zu\nstart=%i\n",ft_strlen(fmt), start);
		i++;

	}
	//printf("\nRES in printf:%i\n", res);
	return (res);

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
