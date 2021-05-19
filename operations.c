#include "push_swap.h"

void	_s(t_stack **head_ref)
{
	int		tmp;
	if (*head_ref && (*head_ref)->next)
	{
		tmp = (*head_ref)->data;
		(*head_ref)->data = (*head_ref)->next->data;
		(*head_ref)->next->data = tmp;
	}
}
void	_ss(t_stack **a, t_stack **b)
{
	_s(a);
	_s(b);
}

void _p(t_stack **a, t_stack **b)
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

void _r(t_stack **head)
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