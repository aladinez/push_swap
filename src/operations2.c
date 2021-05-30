/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:54:40 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 19:07:25 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
