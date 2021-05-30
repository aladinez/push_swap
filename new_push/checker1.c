/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:20:07 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 15:52:36 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap1.h"

int		main(int argc, char **argv)
{
	t_data	data;
    char	*line;
	int		ret;

	data.size = 0;
	data.stack = NULL;
	if (argc == 1)
		return (0);
	else if (check_args((argv + 1), &data) < 0 || is_dupp(&data) < 0) // passing data to checkargs
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
    data.b_index = data.size;
    while ((ret = get_next_line(&line)) > 0)
	{
		if (run_instruction(line, &data))
		{
			my_free(&data, &line);
			return (0);
		}
		free(line);
	}
	if (line[0])
	{
		ft_putstr_fd("Error\n", 2);
		my_free(&data, &line);
		return (0);
	}
    if (is_A_sorted(data))
		ft_putstr_fd("OK\n", 2);
    else
		ft_putstr_fd("KO\n", 2);
	my_free(&data, &line);
	return (0);
}
