#include "push_swap.h"


void	free_stack(t_stack *head)
{
	if (head)
	{
		t_stack *tmp;
		
		while (head != NULL)
		{
		tmp = head;
		head = head->next;
		free(tmp);
		}
	}
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	if (argc == 1 || (argc == 2 && is_number(argv[1])))
	{
		ft_putstr_fd("0 instructions\n", 2);
		return (0);
	}
	else if (check_args((argv + 1), &stack_a) < 0 || is_dupp(stack_a) < 0)
	{
		ft_putstr_fd("ERROR\n", 2);
		// return (0);
	}
	if (is_sorted(stack_a))
	{
		ft_putstr_fd("sorted\n", 2);
		// TODO : free stack_a
		return (0);
	}
	while (stack_a)
    {
        printf("%d --> ", stack_a->data);
        stack_a = stack_a->next;
    }
	// while (1)
	// 	;
	return (0);

}
// gcc push_swap.c stack_modifers.c libft/libft.a -o push
// ./push 1 2 3 4 5 6 