/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:36:28 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 19:06:30 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!quick_sort(&data))
		free_data(&data);
	return (0);
}
