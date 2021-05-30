/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:16:06 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 19:07:20 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	/*
	** check if there is a dupplicated num, and frees the stack if TRUE.
	*/
int	is_dupp(t_data *data)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < data->size)
	{
		tmp = data->stack[i];
		j = i + 1;
		while (j < data->size)
		{
			if (data->stack[j] == tmp)
			{
				free_data(data);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_number(char *str)
{
	int	i;

	if (!(str[0] == '-') && !ft_isdigit(str[0]))
		return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	num_join(t_data *data, int num)
{
	int		*new_stack;
	int		i;

	new_stack = (int *)malloc((data->size + 1) * sizeof(int));
	i = 0;
	new_stack[i] = num;
	while (i < data->size)
	{
		new_stack[i + 1] = data->stack[i];
		i++;
	}
	if (data->stack)
		free(data->stack);
	data->stack = new_stack;
	data->size++;
}

int	check_args(char **str, t_data *data)
{
	int		i;
	int		num;
	long	check_num;

	i = 0;
	while (str[i])
	{
		if (!is_number(str[i]))
			return (-1);
		check_num = ft_atoi(str[i]);
		if (check_num > 2147483647 || check_num < -2147483648)
			return (-1);
		num = (int)check_num;
		num_join(data, num);
		i++;
	}
	return (1);
}

int	is_A_sorted(t_data data)
{
	int	i;

	i = 0;
	while (i < data.size - 1)
	{
		if (data.stack[i] < data.stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
