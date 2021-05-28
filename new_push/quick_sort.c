/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:43:38 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/28 16:23:05 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap1.h"

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
	i = 0;
	while (i < data->size)
	{
		printf("|%d|", dst[i]);
		i++;
	}
	printf("\n");
	return (dst);
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
	
	while (A_chunks)
	{
		printf("index[0] = %d\nindex[1] = %d\nstatus = %d\n\n", A_chunks->index[0], A_chunks->index[1], A_chunks->status);
		A_chunks = A_chunks->next;
	}

    // while (1)
    // {
    //     if (is_chunk_sorted(*data, A_chunks->index[0], A_chunks->index[1]) && !B_chunks)
    //         break ;
    //     else if (is_chunk_sorted(*data, A_chunks->index[0], A_chunks->index[1]))
    //     {
    //         // B to A
    //     }
    //     else
    //     {
    //         // A to B

    //     }
    // }
	return (SUCCESS);

}