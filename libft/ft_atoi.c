/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:23:51 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/10/21 17:02:08 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	num;
	long	max;

	num = 0;
	sign = 1;
	max = 9223372036854775807;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	while (*str != 0 && (*str >= 48 && *str <= 57))
	{
		if (num <= (max - (*str - 48)) / 10)
			num = num * 10 + (*str - 48);
		else
		{
			num = (sign == 1 ? -1 : 0);
			break ;
		}
		str++;
	}
	return (sign * num);
}
