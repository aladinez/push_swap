/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:07:51 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 21:46:22 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SORTED		1
# define UNSORTED	0
# define ERROR		0
# define SUCCESS	1

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../gnl/get_next_line.h"

typedef struct s_data {
	int		*stack;
	int		size;
	int		b_index;
	int		pivot;
}t_data;

typedef struct s_chunk {
	int				index[2];
	int				status;
	struct s_chunk	*next;
}t_chunk;

int		is_number(char *str);
int		is_dupp(t_data *data);
int		check_args(char **str, t_data *data);
void	num_join(t_data *data, int num);
void	free_data(t_data *data);
int		is_A_sorted(t_data data);
void	swap(int *a, int *b);
void	shift_up(int *stack, int start, int end);
void	shift_down(int *stack, int start, int end);
void	sa_(t_data *data, int a);
void	sb_(t_data *data, int a);
void	ss_(t_data *data, int a);
void	pa_(t_data *data, int a);
void	pb_(t_data *data, int a);
void	ra_(t_data *data, int a);
void	rb_(t_data *data, int a);
void	rr_(t_data *data, int a);
void	rra_(t_data *data, int a);
void	rrb_(t_data *data, int a);
void	rrr_(t_data *data, int a);
int		quick_sort(t_data *data);
int		is_chunk_sorted(t_data data, int start, int end);
int		initialise_chunks(t_data data, t_chunk **a, t_chunk **b);
int		push_chunk(t_chunk **head, int start, int end, int i);
void	sort_arr(int *arr, int size);
void	a_to_b(t_data *data, t_chunk **a, t_chunk **b);
void	b_to_a(t_data *data, t_chunk **a, t_chunk **b);
int		run_instruction(char *str, t_data *data);
int		my_strcmp(char *str1, char *str2);
void	my_free(t_data *data, char **line);
int		run_atob_inst(t_data *data, t_chunk **a, int start, int end);
int		pick_B_pivot(t_data data, int start, int end, int *push_num);
int		pick_pivot(t_data data, int start, int end, int *push_num);
int		is_chunk_sorted(t_data data, int start, int end);
void	delete_chunk(t_chunk **a);
void	free_chunks(t_chunk **a);
long	ft_atoi(const char *str);
int		count_num(char str, long *num, long max, long sign);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
int		sort_three(t_data *data);
int		*copyandsort(t_data *data);
int		get_next_line(char **line);
char	*my_strjoin(char *s, char c);

#endif
