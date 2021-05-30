/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:42:29 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 18:03:58 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap1.h"

void	check_a_sides(t_data *data, int *start, int *end, int *size)
{
	if (data->stack[*start] < data->pivot && data->stack[*end] < data->pivot)
	{
		if (data->stack[*end] < data->stack[*start])
		{
			pb_(data, 1);
			*end -= 1;
			*size -= 1;
		}
		else
		{
			rra_(data, 1);
			pb_(data, 1);
			*end -= 1;
			*size -= 1;
		}
	}
	else if (data->stack[*start] < data->pivot)
	{
		rra_(data, 1);
		pb_(data, 1);
		*end -= 1;
		*size -= 1;
	}
}

int	run_atob_inst(t_data *data, t_chunk **a, int start, int end)
{
	int		i;
	int		size;

	i = 0;
	data->pivot = pick_pivot(*data, (*a)->index[0], (*a)->index[1], &size);
	while (size)
	{
		if (!(*a)->next && data->stack[start] < data->pivot)
			check_a_sides(data, &start, &end, &size);
		else if (data->stack[end] < data->pivot)
		{
			pb_(data, 1);
			end--;
			size--;
		}
		else
		{
			ra_(data, 1);
			i++;
		}
	}
	while ((*a)->next && (i--))
		rra_(data, 1);
	return (end);
}

void	a_to_b(t_data *data, t_chunk **a, t_chunk **b)
{
	int	i;

	i = UNSORTED;
	if ((*a)->index[1] - (*a)->index[0] == 2)
	{
		if (data->stack[(*a)->index[0]] < data->stack[(*a)->index[1] - 1])
			sa_(data, 1);
		(*a)->status = 1;
		return ;
	}
	else if ((*a)->index[1] - (*a)->index[0] == 1)
	{
		(*a)->status = 1;
		return ;
	}
	else
		(*a)->index[1] = run_atob_inst(data, a, (*a)->index[0],
				(*a)->index[1] - 1) + 1;
	if (*b)
		push_chunk(b, data->b_index, (*b)->index[0], i);
	else
		push_chunk(b, data->b_index, data->size, i);
}
