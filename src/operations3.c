/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:56:05 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 19:23:39 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_data(t_data *data)
{
	if (data)
		free(data->stack);
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
