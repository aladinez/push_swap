/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:08:02 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/22 11:55:07 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

int main(int argc, char **argv)
{
	t_stack *stack_a;
	if (argc == 1 || (argc == 2 && is_number(argv[1])))
	{
		ft_putstr_fd("0 instructions\n", 2);
		return (0);
	}
	else if (check_args((argv + 1), &stack_a) < 0 || is_dupp(&stack_a) < 0)
	{
		// TODO: free stack if is_dupp < 0
		ft_putstr_fd("ERROR\n", 2);
		while (1)
			;
		
		return (0);
	}
	if (is_sorted(stack_a))
	{
		ft_putstr_fd("sorted\n", 2);
		free_stack(&stack_a);
		return (0);
	}
	// TODO: check if the argument is not int. 
	// quick sort, insertion sort.

	// t_stack *stack_b;

	// push(&stack_b, 4);
	// push(&stack_b, 3);
	// push(&stack_b, 2);
	// push(&stack_b, 1);

	// print_stack(stack_a);
	// print_stack(stack_b);
	// printf("\n");
	
	// rrr_(&stack_a, &stack_b);

	print_stack(stack_a);
	// print_stack(stack_b);


	// while (1)
	// 	;
	return (0);
}
