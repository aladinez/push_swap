/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:08:11 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/24 18:04:02 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		is_number(char *str)
{
	int i;
	if (!(str[0] == '-') && !ft_isdigit(str[0]))
		return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		check_args(char **str, t_stack **root)
{
	int		i;
	int		num;
	long 	check_num;

	i = 0;
	while (str[i])
	{
		if (!is_number(str[i]))
			return  (-1);
		check_num = ft_atoi(str[i]);
		if (check_num > 2147483647 || check_num < -2147483648)
			return (-1);
		num = (int)check_num;
		push_back(root, num);
		i++;
	}
	return (1);
}

int		is_dupp(t_stack **root)
{
	// check if there is a dupplicated num, and frees the stack if TRUE.
	t_stack *tmp;
	t_stack *root_2;
	root_2 = *root;

	while ((*root)->next != NULL) 
	{
		// Starting from the next node
		tmp = (*root)->next;
		while (tmp != NULL)
		{
			// If some duplicate node is found
			if ((*root)->data == tmp->data)
			{
				free_stack(&root_2);
				return (-1);
			}
			tmp = tmp->next;
		}
		*root = (*root)->next;
	}
	*root = root_2;
	return (1);
}

int		is_sorted(t_stack *root)
{
	t_stack *tmp;

	tmp = root;
	while (root && root->next)
	{
		// printf("root : %d | root->next : %d\n", root->data, root->next->data);
		if (root->data > root->next->data) // WTF?
			return (0);

		root = root->next;
	}
	root = tmp;
	return (1);
}
