/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:08:07 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/24 18:08:14 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_(t_stack **head_ref)
{
	int		tmp;

	if (*head_ref && (*head_ref)->next)
	{
		tmp = (*head_ref)->data;
		(*head_ref)->data = (*head_ref)->next->data;
		(*head_ref)->next->data = tmp;
	}
}

void	ss_(t_stack **a, t_stack **b)
{
	sa_(a);
	sa_(b);
}

void	pa_(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (*b)
	{
		push(a, (*b)->data);
		tmp = *b;
		*b = (*b)->next;
		free(tmp);
	}
}

void	ra_(t_stack **head)
{
	t_stack *tmp;
	int		tmp_data;
	int		head_data;

	tmp = *head;
	head_data = (*head)->data;
	while (*head && (*head)->next)
	{
		(*head)->data = (*head)->next->data;
		*head = (*head)->next;
	}
	(*head)->data = head_data;
	*head = tmp;
}

void	rr_(t_stack **a, t_stack **b)
{
	ra_(a);
	ra_(b);
}

void	rra_(t_stack **head)
{
	t_stack *tmp;
	t_stack *root;

	if (*head && (*head)->next)
	{
		root = *head;
		while (((*head)->next)->next)
		{
			*head = (*head)->next;
		}
		tmp = (*head)->next;
		(*head)->next = NULL;
		tmp->next = root;
		*head = tmp;
	}
}

void	rrr_(t_stack **a, t_stack **b)
{
	rra_(a);
	rra_(b);
}
