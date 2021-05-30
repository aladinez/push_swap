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

void	sa_(t_data *data, int a)
{
	if (data->b_index > 1)
		swap(&data->stack[data->b_index - 1], &data->stack[data->b_index - 2]);
	if (a)
		ft_putstr_fd("sa\n", 1);
}
void	sb_(t_data *data, int a)
{
	if (data->b_index < data->size - 1)
		swap(&data->stack[data->b_index], &data->stack[data->b_index + 1]);
	if (a)
		ft_putstr_fd("sb\n", 1);
}

void	ss_(t_data *data, int a)
{
	sa_(data, 0);
	sb_(data, 0);
	if (a)
		ft_putstr_fd("ss\n", 1);
}

void	pb_(t_data *data, int a)
{
	if (data->b_index > 0)
		data->b_index--;
	if (a)
		ft_putstr_fd("pb\n", 1);
	
}
void	pa_(t_data *data, int a)
{
	if (data->b_index < data->size)
		data->b_index++;
	if (a)
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

void	rr_(t_data *data, int a)
{
	ra_(data, 0);
	rb_(data, 0);
	if (a)
		ft_putstr_fd("rr\n", 1);
}

void 	rra_(t_data *data, int a)
{
	if (data->b_index > 1)
		shift_up(data->stack, 0, data->b_index);
	if (a)
		ft_putstr_fd("rra\n", 1);
}

void	rrb_(t_data *data, int a)
{
	if (data->size > data->b_index + 1)
		shift_down(data->stack, data->b_index, data->size);
	if (a)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr_(t_data *data, int a)
{
	rra_(data, 0);
	rrb_(data, 0);
	if (a)
		ft_putstr_fd("rrr\n", 1);
}