/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:05:14 by adosiak           #+#    #+#             */
/*   Updated: 2017/03/10 14:07:45 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int n1;

	n1 = n;
	if (n == -2147483648)
		n1 = n / 10;
	if (n1 < 0)
	{
		n1 = n1 * (-1);
		ft_putchar_fd('-', fd);
	}
	if (n1 < 10)
		ft_putchar_fd(n1 + '0', fd);
	else
		ft_putnbr_fd(n1 / 10, fd);
	if (n1 >= 10)
		ft_putnbr_fd(n1 % 10, fd);
	if (n == -2147483648)
		ft_putchar_fd(8 + '0', fd);
}
