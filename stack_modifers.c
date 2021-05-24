/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_modifers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:08:28 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/24 18:11:58 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack *newNode(int data)
// {
//     t_stack* newStackNode;
//     newStackNode = (t_stack *)malloc(sizeof(t_stack));
//     newStackNode->data = data;
//     newStackNode->next = NULL;
//     return (newStackNode);
// }

void	push_back(t_stack** root, int data)
{
    t_stack* newStackNode;
	t_stack *tmp;
	
    newStackNode = (t_stack *)malloc(sizeof(t_stack));
    newStackNode->data = data;
    // newStackNode->next = *root;
    newStackNode->next = NULL;
	if (*root == NULL)
    	*root = newStackNode;
	else
	{
		tmp = *root;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = newStackNode;
	}
    // printf("%d pushed to stack\n", data);
}

void	push(t_stack** root, int data)
{
    t_stack* newStackNode;
    newStackNode = (t_stack *)malloc(sizeof(t_stack));
    newStackNode->data = data;
    newStackNode->next = *root;
    *root = newStackNode;
    // printf("%d pushed to stack\n", data);
}

void	free_stack(t_stack **head_ref)
{
	t_stack *head;
	t_stack *tmp;

	head = *head_ref;	
	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	*head_ref = NULL;
}

void	print_stack(t_stack *head)
{
	t_stack *tmp;

	tmp = head;
	while (head)
	{
		printf("%d --> ", head->data);
        head = head->next;
	}
	head = tmp;
	printf("\n");
}
