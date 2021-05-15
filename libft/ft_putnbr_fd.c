/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:14:58 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/10/14 19:59:47 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	unsigned int	num;
	unsigned int	n1;
	unsigned int	n2;

	i = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n2 = -n;
	}
	else
		n2 = n;
	n1 = n2;
	while (n1 /= 10)
		i *= 10;
	while (i)
	{
		num = n2 / i;
		num = (num % 10) + 48;
		ft_putchar_fd(num, fd);
		i /= 10;
	}
}
