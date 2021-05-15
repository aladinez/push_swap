#include "push_swap.h"

void ft_putchar(char *str)
{
	int i;

	i = -1;
	while(str[++i])
		write(1, &str[i], 1);
}

int		is_number(char *str)
{
	int i;

	i = 0;
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

	i = 0;
	while (str[i])
	{
		if (!is_number(str[i]))
			return  (-1);
		num = ft_atoi(str[i]);
		push(root, num);
		i++;
	}
	return (1);

}

int		is_dupp(t_stack *root)
{
	t_stack *tmp;
	t_stack *root_2;
	root_2 = root;

	
	while (root->next != NULL) 
	{
		// Starting from the next node
		tmp = root->next;
		while (tmp != NULL)
		{
			// If some duplicate node is found
			if (root->data == tmp->data) 
				return (-1);
			tmp = tmp->next;
		}
		root = root->next;
	}
	root = root_2;
	return (1);
}

int		is_sorted(t_stack *root)
{
	t_stack *tmp;

	tmp = root;
	while (root && root->next)
	{
		printf("root : %d | root->next : %d\n", root->data, root->next->data);
		if (root->data > root->next->data) // WTF?
			return (-1);

		root = root->next;
	}
	root = tmp;
	return (1);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	if (argc < 3 || check_args((argv + 1), &stack_a) < 0 || is_dupp(stack_a) < 0 || is_sorted(stack_a) < 0)
	{
		ft_putchar("0 instruction\n");
		// return (0);
	}
	while (stack_a)
    {
        printf("%d --> ", stack_a->data);
        stack_a = stack_a->next;
    }
	return (0);

}
// gcc push_swap.c stack_modifers.c libft/libft.a -o push
// ./push 1 2 3 4 5 6 