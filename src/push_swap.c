/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:36:28 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 21:42:30 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copyandsort(t_data *data)
{
	int	*sorted_stack;
	int	i;

	sorted_stack = (int *)malloc(3 * sizeof(int));
	i = 0;
	while (i < 3)
	{
		sorted_stack[i] = data->stack[i];
		i++;
	}
	sort_arr(sorted_stack, 3);
	return (sorted_stack);
}

int	sort_three(t_data *data)
{
	int	*sorted_stack;

	if (data->size == 3)
	{
		sorted_stack = copyandsort(data);
		while (data->stack[0] != sorted_stack[2])
			ra_(data, 1);
		if (data->stack[2] > data->stack[1])
			sa_(data, 1);
		free(sorted_stack);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.size = 0;
	data.stack = NULL;
	if (argc == 1 || (argc == 2 && is_number(argv[1])))
		return (0);
	else if (check_args((argv + 1), &data) < 0 || is_dupp(&data) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (is_A_sorted(data))
	{
		free_data(&data);
		return (0);
	}
	data.b_index = data.size;
	if (sort_three(&data) || !quick_sort(&data))
		free_data(&data);
	return (0);
}
