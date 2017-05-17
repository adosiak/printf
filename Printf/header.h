/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:26:00 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/16 17:37:26 by adosiak          ###   ########.fr       */
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
	char	*length;
	char	*type;
}			t_param;


#endif
