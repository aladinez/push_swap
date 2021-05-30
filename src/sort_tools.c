/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:17:41 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 19:23:34 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pick_B_pivot(t_data data, int start, int end, int *push_num)
{
	int	i;
	int	size;
	int	*arr;

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

int	pick_pivot(t_data data, int start, int end, int *push_num)
{
	int	i;
	int	size;
	int	*arr;

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

int	is_chunk_sorted(t_data data, int start, int end)
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

int	push_chunk(t_chunk **head, int start, int end, int i)
{
	t_chunk	*new_chunk;

	new_chunk = (t_chunk *)malloc(sizeof(t_chunk));
	if (!new_chunk)
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
