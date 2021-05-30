/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:23:51 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 19:57:57 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	long	sign;
	long	num;
	long	max;

	num = 0;
	sign = 1;
	max = 9223372036854775807;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str != 0 && (*str >= 48 && *str <= 57))
	{
		if (count_num(*str, &num, max, sign))
			break ;
		str++;
	}
	return (sign * num);
}

int	count_num(char str, long *num, long max, long sign)
{
	if (*num <= (max - (str - 48)) / 10)
		*num = *num * 10 + (str - 48);
	else
	{
		if (sign == 1)
			*num = -1;
		else
			*num = 0;
		return (1);
	}
	return (0);
}
