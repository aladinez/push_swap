/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alae <alae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:43:38 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/29 22:46:27 by alae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap1.h"

int		pick_B_pivot(t_data data, int start, int end, int *push_num)
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
	i = arr[(size / 2)];
	if (size % 2 == 0)
		*push_num = size / 2 - 1;
	else
		*push_num = size / 2;
	free(arr);
	return (i);
}

int		pick_pivot(t_data data, int start, int end, int *push_num)
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
	// i = 0;
	// while (i < size)
	// {
	// 	printf("| %d", arr[i]);
	// 	i++;
	// }
	// printf("\n");
	i = arr[(size / 2)];
	*push_num = size / 2;
	// printf("size = %d ---- push_num= %d\n", size, *push_num);
	// if (size % 2 == 0)
	// 	*push_num = size / 2;
	// else
	// 	*push_num = (size / 2) + 1;
	free(arr);
	return (i);
}

int		is_chunk_sorted(t_data data, int start, int end)
{
	int	i;
	i = start;
	while (i < end - 1)
	{
		if (data.stack[i] < data.stack[i + 1]) 
			return (0);
		i++;
	}
	return (1);
}

int    push_chunk(t_chunk **head, int start, int end, int i)
{
    t_chunk *new_chunk;

	if (!(new_chunk = (t_chunk *)malloc(sizeof(t_chunk))))
		return (ERROR);
    new_chunk->index[0] = start;
    new_chunk->index[1] = end;
	if (i)
   		new_chunk->status = SORTED;
	else
   		new_chunk->status = UNSORTED;
	new_chunk->next = *head;
	*head = new_chunk;
	
	return (SUCCESS);
}

int    initialise_chunks(t_data data, t_chunk **a, t_chunk **b)
{
    *b = NULL;
	*a = NULL;
    if (!(push_chunk(a, 0, data.size, UNSORTED)))
		return (ERROR);
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
			if (arr[j] > arr[j + 1])
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
	//TODO: no need to copy and sort the array;
	sort_arr(dst, data->size);
	return (dst);
}

void	b_to_a(t_data *data, t_chunk **a, t_chunk **b)
{
	int pivot;
	int size;
	int start;
	int end;
	t_chunk *tmp;

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
		if ((*a)->next)
		{
			tmp = *a;
			*a = (*a)->next;
			free(tmp);
			tmp = NULL;
		}
		else{
			free(*a);
			*a = NULL;
		}
	}
	else if (end - start == 0)
	{	
		pa_(data, 1);
		start++;
		push_chunk(b, (*b)->index[1], data->b_index, SORTED);
		if ((*a)->next)
		{
			tmp = *a;
			*a = (*a)->next;
			free(tmp);
			tmp = NULL;
		}
		else{
			free(*a);
			*a = NULL;
		}
		return ;
	}
	else {
		int i = 0;
		pivot = pick_B_pivot(*data, (*a)->index[0], (*a)->index[1], &size);
		// size = end - start; // size , max num of operations we will do
		// size = (*a)->index[1] - (*a)->index[0];
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

void	a_to_b(t_data *data, t_chunk **a, t_chunk **b)
{
	int pivot;
	int size;
	int start;
	int end;

	start = (*a)->index[0];
	end = (*a)->index[1] - 1;
	int i = UNSORTED;
	if (end - start == 1)
	{
		if (data->stack[start] < data->stack[end])
			sa_(data, 1);
		(*a)->status = 1;
		return ;
	}
	else if (end - start == 0)
	{
		(*a)->status = 1;
		return ;
	}
	else
	{
		int i = 0;
		pivot = pick_pivot(*data, (*a)->index[0], (*a)->index[1], &size);
		// printf("INDE[0] = %d --INDE[1] = %d\npivot : %d\nsize = %d\n", (*a)->index[0], (*a)->index[1], pivot, size);	
		// sleep(5);
		// size = end - start + 1; // size , max num of operations we will do
		// size = (*a)->index[1] - (*a)->index[0];
		while (size)
		{
			if (!(*a)->next && data->stack[start] < pivot && data->stack[end] < pivot)
			{
				if (data->stack[end] < data->stack[start])
				{
					pb_(data, 1);
					end--;	
					size--;
	
				}
				else
				{
					rra_(data, 1);
					pb_(data, 1);
					end--;
					size--;
				}
			}
			else if (!(*a)->next && data->stack[start] < pivot)
			{
				rra_(data, 1);
				pb_(data, 1);
				end--;
				size--;
			}
			else if (data->stack[end] < pivot)
			{
				pb_(data, 1);
				end--;
				size--;

			}
			else
			{
				ra_(data, 1);
				// printf("AAA\n");
				i++;
			}
			// size--;
		}
		while ((*a)->next && (i--))
			rra_(data, 1);
	}
	(*a)->index[1] = end + 1;
	if (*b)
		push_chunk(b, data->b_index, (*b)->index[0], i);
	else
		push_chunk(b, data->b_index, data->size, i);
}

int quick_sort(t_data *data)
{
    t_chunk *A_chunks;
    t_chunk *B_chunks;
	int		*sorted_stack;

    if (!initialise_chunks(*data, &A_chunks, &B_chunks) ||
		!(sorted_stack = copyAndSort(data)))
		return (ERROR);
    while (1)
    {
        if (A_chunks->status == SORTED && !B_chunks)
            break ;
        else if (A_chunks->status == SORTED)
        {
            b_to_a(data, &B_chunks, &A_chunks);
        }
        else
        {
            a_to_b(data, &A_chunks, &B_chunks);
        }
	// print_stack(*data);
	// sleep(5);
    }
	return (SUCCESS);

}

// errorrrr ./a.out 6 5 4 8 9 7 1 2 3 0 


// last error : ./a.out 6 5 4 8 9 3 -8 0 7 1 2  --> see screenshot

// TODO: no need sort the stack stack in another array