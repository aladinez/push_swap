/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:07:02 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/25 19:07:03 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		my_strcmp(char *str1, char *str2)
{
	int i;

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

int	run_instruction(char *str, t_stack **a, t_stack **b)
{
	if (!strcmp(str, "sa"))
		sa_(a);
	else if (!strcmp(str, "sb"))
		sa_(b);
	else if (!strcmp(str, "ss"))
		ss_(a, b);
	else if (!strcmp(str, "pa"))
		pa_(a, b);
	else if (!strcmp(str, "pb"))
		pa_(b, a);
	else if (!strcmp(str, "ra"))
		ra_(a);
	else if (!strcmp(str, "rb"))
		ra_(b);
	else if (!strcmp(str, "rr"))
		rr_(a, b);
	else if (!strcmp(str, "rra"))
		rra_(a);
	else if (!strcmp(str, "rrb"))
		rra_(b);
	else if (!strcmp(str, "rrr"))
		rrr_(a, b);
	else
	{
		ft_putstr_fd("Error from check_instruction\n", 2);
		free_stack(a);
		free_stack(b);
		return (1);
	}
	printf("stack A: "); print_stack(*a);
	printf("stack B: "); print_stack(*b);
	printf("\n");
	return (0);
}


int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char	*line;
	int		ret;

	if (argc == 1)
		return (0);
	else if (check_args((argv + 1), &stack_a) < 0 || is_dupp(&stack_a) < 0)
	{
		// TODO: free stack if is_dupp < 0 : done in is_dupp func
		ft_putstr_fd("Error\n", 2);
		return (0);
	}

	line = NULL;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (run_instruction(line, &stack_a, &stack_b))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	//--------------- IDK WHY ------------
	// if (line[0])
	// {
	// 	ft_putstr_fd("Error\n", 2);
	// 	return (0);
	// }
	free(line);
	if (is_sorted(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0); 
}


// gcc checker.c stack_modifers.c error_check.c operations.c libft/libft.a gnl/get_next_line.c gnl/get_next_line_utils.c -o checker