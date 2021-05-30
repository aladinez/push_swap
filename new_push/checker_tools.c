/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:19:21 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 21:06:57 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	run_instruction(char *str, t_data *data)
{
	if (!my_strcmp(str, "sa"))
		sa_(data, 0);
	else if (!my_strcmp(str, "sb"))
		sb_(data, 0);
	else if (!my_strcmp(str, "ss"))
		ss_(data, 0);
	else if (!my_strcmp(str, "pa"))
		pa_(data, 0);
	else if (!my_strcmp(str, "pb"))
		pb_(data, 0);
	else if (!my_strcmp(str, "ra"))
		ra_(data, 0);
	else if (!my_strcmp(str, "rb"))
		rb_(data, 0);
	else if (!my_strcmp(str, "rr"))
		rr_(data, 0);
	else if (!my_strcmp(str, "rra"))
		rra_(data, 0);
	else if (!my_strcmp(str, "rrb"))
		rrb_(data, 0);
	else if (!my_strcmp(str, "rrr"))
		rrr_(data, 0);
	else
		return (1);
	return (0);
}

int	my_strcmp(char *str1, char *str2)
{
	int	i;

	if (ft_strlen(str1) != ft_strlen(str2))
		return (1);
	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

void	my_free(t_data *data, char **line)
{
	free_data(data);
	if (*line)
		free(*line);
}
