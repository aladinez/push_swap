/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:36:28 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/28 14:01:48 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap1.h"


void	free_data(t_data *data)
{
	if (data)
	{
		free(data->stack);
		// free(data);
	}
}


int		is_dupp(t_data *data)
{
	// check if there is a dupplicated num, and frees the stack if TRUE.
	int i;
	int j;
	int tmp;
	
	i = 0;
	while (i < data->size) 
	{
		tmp = data->stack[i];
		j = i + 1;
		while (j < data->size)
		{
			if (data->stack[j] == tmp)
			{
				// TODO: free data.
				free(data->stack);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

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

void	num_join(t_data *data, int num)
{
	int		*new_stack;
	int		i;

	new_stack = (int *)malloc((data->size + 1) * sizeof(int));
	i = 0;
	new_stack[i] = num;
	while (i < data->size)
	{
		new_stack[i + 1] = data->stack[i];
		i++;
	}
	if (data->stack)
		free(data->stack);
	data->stack = new_stack;
	data->size++;
}

int		check_args(char **str, t_data *data)
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
		// push_back(root, num);
		num_join(data, num);
		i++;
	}
	return (1);
}

void	print_A(t_data data)
{
	int		i;
	
	i = data.b_index - 1;
	while(i >= 0)
	{
		ft_putnbr_fd(data.stack[i], 1);
		ft_putstr_fd(" --> ", 1);
		i--;
	}
	ft_putchar_fd('\n', 1);
}
void	print_B(t_data data)
{
	int		i;
	
	i = data.b_index;
	while(i < data.size)
	{
		ft_putnbr_fd(data.stack[i], 1);
		ft_putstr_fd(" --> ", 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}



int		is_A_sorted(t_data data)
{
	int	i;

	i = 0;
	while (i < data.size - 1)
	{
		// printf("root : %d | root->next : %d\n", root->data, root->next->data);
		if (data.stack[i] < data.stack[i + 1]) 
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	// t_stack *stack_a;
	t_data	data;
	
	data.size = 0;
	data.stack = NULL;
	if (argc == 1 || (argc == 2 && is_number(argv[1])))
	{
		ft_putstr_fd("0 instructions\n", 2);
		return (0);
	}
	else if (check_args((argv + 1), &data) < 0 || is_dupp(&data) < 0) // passing data to checkargs
	{
		ft_putstr_fd("ERROR\n", 2);
		// return (0);
	}
	if (is_A_sorted(data))
	{
		ft_putstr_fd("sorted\n", 2);
		free(data.stack);
		return (0);
	}
	data.b_index = data.size;
	quick_sort(&data);
	

	// print_stack(data);

	// print_A(data);
	// print_B(data);
	


	
	// data.stack = NULL;
	// while (1)
	// 	;


	return (0);
}

 
void	print_stack(t_data data)
{
	int i;

	i = 0;
	printf ("\n-----------------------------------\n");
	while (i < data.b_index)
	{
		printf("| %d ", data.stack[i]);
		i++;
	}
	printf ("|---");
	while (i < data.size)
	{
		printf("| %d ", data.stack[i]);
		i++;
	}
	printf ("|\n----------------------------------\n");

}

// gcc push_swap1.c ../libft/libft.a  operations1.c