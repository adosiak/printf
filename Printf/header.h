/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:26:00 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/23 15:49:37 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define HEADER_H
# ifdef HEADER_H

#include <stdarg.h>
#include <stdlib.h>


typedef struct s_param
{
	int		parameter;
	char	*flag;
	int 	width;
	int		precision;
	int		length;
	int		type;
	char	*extra;
}			t_param;

extern char g_lengths[8][3];
extern char g_types[14][2];


#endif
