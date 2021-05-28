/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:43:38 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/28 20:37:48 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap1.h"

int		pick_pivot(t_data data, int start, int end)
{
	int i;
	int size;
	int *arr;
	
	if (start == end)
		return (data.stack[start]);
	size = end - start;
	arr = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		arr[i] = data.stack[start + i];
		i++;
	}
	sort_arr(arr, size);
	i = arr[(int)(size / 2)];
	free(arr);
	return (i);
}

int		is_chunk_sorted(t_data data, int start, int end)
{
	int	i;

	i = start;
	while (i < end - 1)
	{
		// printf("root : %d | root->next : %d\n", root->data, root->next->data);
		if (data.stack[i] < data.stack[i + 1]) 
			return (0);
		i++;
	}
	return (1);
}

int    push_chunk(t_chunk **head, int start, int end)
{
    t_chunk *new_chunk;

	if (!(new_chunk = (t_chunk *)malloc(sizeof(t_chunk))))
		return (ERROR);
    new_chunk->index[0] = start;
    new_chunk->index[1] = end;
    new_chunk->status = UNSORTED;

	new_chunk->next = *head;
	*head = new_chunk;
	
	return (SUCCESS);
}

int    initialise_chunks(t_data data, t_chunk **a, t_chunk **b)
{
    *b = NULL;
	*a = NULL;
    if (!(push_chunk(a, 0, data.size)))
		return (ERROR);
	// while (a)
	// {
	// 	printf("index[0] = %d\nindex[1] = %d\nstatus = %d\n\n", a->index[0], a->index[1], a->status);
	// 	a = a->next;
	// }
	return (SUCCESS);
}

void	sort_arr(int *arr, int size)
{
	int i;
	int j;
	
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] < arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

int		*copyAndSort(t_data *data)
{
	int 	i;
	int		*dst;

	i = 0;
	if (!(dst = (int *)malloc(data->size * sizeof(int))))
		return (ERROR);
	while (i < data->size)
	{
		dst[i] = data->stack[i];
		i++;
	}
	sort_arr(dst, data->size);
	// i = 0;
	// while (i < data->size)
	// {
	// 	printf("|%d|", dst[i]);
	// 	i++;
	// }
	// printf("\n");
	return (dst);
}

void	b_to_a(t_data *data, t_chunk **a, t_chunk **b)
{
	int pivot;
	int size;
	int start;
	int end;

	start = (*a)->index[0];
	end = (*a)->index[1] - 1;
	size = end - start + 1; // size , max num of operations we will do
	pivot = pick_pivot(*data, start, end);
	if (end - start == 2)
	{
		if ((*a)->index[start] < (*a)->index[start + 1])
			sb_(data);
		pa_(data);
		pa_(data);
		
		return ;
	}
	while (--size)
	{
		if (data->stack[start] <= pivot && data->stack[end] <= pivot)
		{
			if (data->stack[start] < data->stack[end])
			{
				pa_(data);
				start++;
			}
			else
			{
				rrb_(data);
				pa_(data);
				start++;
			}
		}
		else if (data->stack[start] <= pivot)
		{
			pa_(data);
			start++;
		}
		else if (data->stack[end] <= pivot)
		{
			rrb_(data);
			pa_(data);
			start++;
		}
		else
			rb_(data);
	}
	(*a)->index[0] = start;
	if (*b)
		push_chunk(b, (*b)->index[1], data->b_index);
	// else
	// 	push_chunk(b, data->b_index, data->size);
}

void	a_to_b(t_data *data, t_chunk **a, t_chunk **b)
{
	int pivot;
	int size;
	int start;
	int end;

	start = (*a)->index[0];
	end = (*a)->index[1] - 1;
	size = end - start + 1; // size , max num of operations we will do
	pivot = pick_pivot(*data, start, end);
	if (end - start == 2)
	{
		sa_(data);
		return ;
	}
	printf("| 0 | 1 | 2 | 3 | 4 | 5 |\n");
	int i = 0;
	while (i < data->size)
	{
		printf("| %d ", data->stack[i]);
		i++;
	}
	printf("|\n");
	while (--size)
	{
		if (data->stack[start] <= pivot && data->stack[end] <= pivot)
		{
			if (data->stack[start] < data->stack[end])
			{
				pb_(data);
				end--;	
			}
			else
			{
				rra_(data);
				pb_(data);
				end--;
			}
		}
		else if (data->stack[start] <= pivot)
		{
			pb_(data);
			end--;
		}
		else if (data->stack[end] <= pivot)
		{
			rra_(data);
			pb_(data);
			end--;
		}
		else
			ra_(data);
	}
	(*a)->index[1] = end + 1;
	if (*b)
		push_chunk(b, data->b_index, (*b)->index[0] );
	else
		push_chunk(b, data->b_index, data->size);
	

	// --- 
	i = 0;
	while (i < data->size)
	{
		printf("%d -> ", data->stack[i]);
		// printf("index[0] = %d\nindex[1] = %d\nstatus = %d\nPIVOT : %D\n\n", A_chunks->index[0], A_chunks->index[1], A_chunks->status, pivot);
		i++;
	}
	printf("\n");
	// ---
}

int quick_sort(t_data *data)
{
    t_chunk *A_chunks;
    t_chunk *B_chunks;
	int		*sorted_stack;

    if (!initialise_chunks(*data, &A_chunks, &B_chunks) ||
		!(sorted_stack = copyAndSort(data)))
		return (ERROR);
	// chunk a is invalid after initialising itttt
	
	// int pivot = pick_pivot(*data, 0, data->size);

    while (1)
    {
        if (is_chunk_sorted(*data, A_chunks->index[0], A_chunks->index[1]) && !B_chunks)
            break ;
        else if (is_chunk_sorted(*data, A_chunks->index[0], A_chunks->index[1]))
        {
            b_to_a(data, &B_chunks, &A_chunks);
        }
        else
        {
            a_to_b(data, &A_chunks, &B_chunks);
        }
		
    }

	
	
	return (SUCCESS);

}