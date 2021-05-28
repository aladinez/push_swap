/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alae <alae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:51:26 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/28 22:25:25 by alae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap1.h"

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa_(t_data *data)
{
	if (data->b_index > 1)
		swap(&data->stack[data->b_index - 1], &data->stack[data->b_index - 2]);
	ft_putstr_fd("sa\n", 1);
}
void	sb_(t_data *data)
{
	if (data->b_index < data->size - 1)
		swap(&data->stack[data->b_index], &data->stack[data->b_index + 1]);
	ft_putstr_fd("sb\n", 1);
}

void	ss_(t_data *data)
{
	sa_(data);
	sb_(data);
}

void	pb_(t_data *data)
{
	if (data->b_index > 0)
		data->b_index--;
	ft_putstr_fd("pb\n", 1);
	
}
void	pa_(t_data *data)
{
	if (data->b_index < data->size)
		data->b_index++;
	ft_putstr_fd("pa\n", 1);
}

void	shift_up(int *stack, int start, int end)
{
	int tmp;
	int i;

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
	int tmp;
	int i;

	i = end - 1;
	tmp = stack[i];
	while (i > start)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = tmp;
}

void 	ra_(t_data *data)
{
	if (data->b_index > 1)
		shift_down(data->stack, 0, data->b_index);
	ft_putstr_fd("ra\n", 1);
}

void	rb_(t_data *data)
{
	if (data->size > data->b_index + 1)
		shift_up(data->stack, data->b_index, data->size);
	ft_putstr_fd("rb\n", 1);
}

void	rr_(t_data *data)
{
	ra_(data);
	rb_(data);
}

void 	rra_(t_data *data)
{
	if (data->b_index > 1)
		shift_up(data->stack, 0, data->b_index);
	ft_putstr_fd("rra\n", 1);
}

void	rrb_(t_data *data)
{
	if (data->size > data->b_index + 1)
		shift_down(data->stack, data->b_index, data->size);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr_(t_data *data)
{
	rra_(data);
	rrb_(data);
}