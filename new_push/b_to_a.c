/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:57:46 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 17:05:29 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap1.h"

// int	run_btoa_inst(t_data *data, t_chunk **a, int start, int end)
// {
// 	int		i;
// 	int		size;

	
// }

void	b_to_a(t_data *data, t_chunk **a, t_chunk **b)
{
	int pivot;
	int size;
	int start;
	int end;
	// t_chunk *tmp;

	start = (*a)->index[0];
	end = (*a)->index[1] - 1;
	int i = UNSORTED;
	if (end - start == 1)
	{
		if (data->stack[start] < data->stack[start + 1])
			sb_(data, 1);
		pa_(data, 1);
		pa_(data, 1);
		i = SORTED;
		start += 2;
		delete_chunk(a);
	}
	else if (end - start == 0)
	{	
		pa_(data, 1);
		start++;
		push_chunk(b, (*b)->index[1], data->b_index, SORTED);
		delete_chunk(a);
		return ;
	}
	else {
		int i = 0;
		pivot = pick_B_pivot(*data, (*a)->index[0], (*a)->index[1], &size);
		while (size)
		{
			if (!(*a)->next && data->stack[start] > pivot && data->stack[end] > pivot)
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
			else if (!(*a)->next && data->stack[end] > pivot)
			{
				rrb_(data, 1);
				pa_(data, 1);
				start++;
				size--;
			}
			else if (data->stack[start] > pivot)
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
	}
	if (*a)
		(*a)->index[0] = start;
	if (*b)
		push_chunk(b, (*b)->index[1], data->b_index, i);
}