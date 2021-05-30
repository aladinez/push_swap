/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:57:46 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 17:54:31 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap1.h"

int	run_btoa_inst(t_data *data, t_chunk **a, int start, int end)
{
	int		i;
	int		size;

	i = 0;
	data->pivot = pick_B_pivot(*data, (*a)->index[0], (*a)->index[1], &size);
	
	while (size)
	{
		if (!(*a)->next && data->stack[start] > data->pivot && data->stack[end] > data->pivot)
		{
			if (data->stack[start] > data->stack[end])
			{
				pa_(data, 1);
				start++;
				size--;
			}
			else
			{
				rrb_(data, 1);
				pa_(data, 1);
				start++;
				size--;
			}
		}
		else if (!(*a)->next && data->stack[end] > data->pivot)
		{
			rrb_(data, 1);
			pa_(data, 1);
			start++;
			size--;
		}
		else if (data->stack[start] > data->pivot)
		{
			pa_(data, 1);
			start++;
			size--;
		}
		else
		{
			rb_(data, 1);
			i++;
		}
		// size--;
	}
	while ((*a)->next && (i--))
		rrb_(data, 1);
	
	return (start);
}

void	b_to_a(t_data *data, t_chunk **a, t_chunk **b)
{
	int	i;

	i = UNSORTED;
	if ((*a)->index[1] - (*a)->index[0] == 2)
	{
		if (data->stack[(*a)->index[0]] < data->stack[(*a)->index[0] + 1])
			sb_(data, 1);
		pa_(data, 1);
		pa_(data, 1);
		i = SORTED;
		(*a)->index[0] += 2;
		delete_chunk(a);
	}
	else if ((*a)->index[1] - (*a)->index[0] == 1)
	{	
		pa_(data, 1);
		(*a)->index[0] += 1;
		push_chunk(b, (*b)->index[1], data->b_index, SORTED);
		delete_chunk(a);
		return ;
	}
	else
		(*a)->index[0] = run_btoa_inst(data, a, (*a)->index[0],
				(*a)->index[1] - 1);
	push_chunk(b, (*b)->index[1], data->b_index, i);
}
