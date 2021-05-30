/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:51:26 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 19:07:23 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	shift_up(int *stack, int start, int end)
{
	int	tmp;
	int	i;

	i = start;
	tmp = stack[i];
	while (i < end - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = tmp;
}

void	shift_down(int *stack, int start, int end)
{
	int	tmp;
	int	i;

	i = end - 1;
	tmp = stack[i];
	while (i > start)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = tmp;
}

void 	ra_(t_data *data, int a)
{
	if (data->b_index > 1)
		shift_down(data->stack, 0, data->b_index);
	if (a)
		ft_putstr_fd("ra\n", 1);
}

void	rb_(t_data *data, int a)
{
	if (data->size > data->b_index + 1)
		shift_up(data->stack, data->b_index, data->size);
	if (a)
		ft_putstr_fd("rb\n", 1);
}
