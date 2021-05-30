/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:17:41 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 15:35:20 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap1.h"

void	free_data(t_data *data)
{
	if (data)
		free(data->stack);
}

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
	i = arr[(size / 2)];
	*push_num = size / 2;
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

void	delete_chunk(t_chunk **a)
{
	t_chunk *tmp;
	
	if ((*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
		tmp = NULL;
	}
	else
	{
		free(*a);
		*a = NULL;
	}
}

void	free_chunks(t_chunk **a)
{
	t_chunk *tmp;
	
	while ((*a))
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
		tmp = NULL;
	}
}