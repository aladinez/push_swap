#include "push_swap1.h"

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

int		run_instruction(char *str, t_data *data)
{
	if (!strcmp(str, "sa"))
		sa_(data, 0);
	else if (!strcmp(str, "sb"))
		sb_(data, 0);
	else if (!strcmp(str, "ss"))
		ss_(data, 0);
	else if (!strcmp(str, "pa"))
		pa_(data, 0);
	else if (!strcmp(str, "pb"))
		pb_(data, 0);
	else if (!strcmp(str, "ra"))
		ra_(data, 0);
	else if (!strcmp(str, "rb"))
		rb_(data, 0);
	else if (!strcmp(str, "rr"))
		rr_(data, 0);
	else if (!strcmp(str, "rra"))
		rra_(data, 0);
	else if (!strcmp(str, "rrb"))
		rrb_(data, 0);
	else if (!strcmp(str, "rrr"))
		rrr_(data, 0);
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

void	my_free(t_data *data, char **line)
{
	free_data(data);
	if (*line)
		free(*line);
}

int		main(int argc, char **argv)
{
	t_data	data;
    char	*line;
	int		ret;

	data.size = 0;
	data.stack = NULL;
	if (argc == 1)
		return (0);
	else if (check_args((argv + 1), &data) < 0 || is_dupp(&data) < 0) // passing data to checkargs
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
    data.b_index = data.size;
    while ((ret = get_next_line(&line)) > 0)
	{
		if (run_instruction(line, &data))
		{
			my_free(&data, &line);
			return (0);
		}
		free(line);
	}
	if (line[0])
	{
		ft_putstr_fd("Error\n", 2);
		my_free(&data, &line);
		return (0);
	}
    if (is_A_sorted(data))
		ft_putstr_fd("OK\n", 2);
    else
		ft_putstr_fd("KO\n", 2);
	my_free(&data, &line);
	return (0);
}


