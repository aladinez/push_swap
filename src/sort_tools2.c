/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:12:39 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 19:13:28 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialise_chunks(t_data data, t_chunk **a, t_chunk **b)
{
	*b = NULL;
	*a = NULL;
	if (!(push_chunk(a, 0, data.size, UNSORTED)))
		return (ERROR);
	return (SUCCESS);
}

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;

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
	t_chunk	*tmp;

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
	t_chunk	*tmp;

	while ((*a))
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
		tmp = NULL;
	}
}
