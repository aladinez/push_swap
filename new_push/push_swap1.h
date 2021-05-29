/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:07:51 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/29 19:06:14 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

#define SORTED 1
#define UNSORTED 0
#define ERROR 0
#define	SUCCESS 1


typedef struct s_data {
	int		*stack;
	int		size;
	int		b_index;
}t_data;

typedef struct s_chunk {
	int index[2];
	int	status;
	struct s_chunk *next;
}t_chunk;


int		is_number(char *str);
void	print_A(t_data data);
void	print_B(t_data data);
int		check_args(char **str, t_data *data);
void	num_join(t_data *data, int num);
void	free_data(t_data *data);
int		is_A_sorted(t_data data);

void	swap(int *a, int *b);
void	shift_up(int *stack, int start, int end);
void	shift_down(int *stack, int start, int end);

void	sa_(t_data *data);
void	sb_(t_data *data);
void	ss_(t_data *data);
void	pa_(t_data *data);
void	pb_(t_data *data);

void 	ra_(t_data *data);
void	rb_(t_data *data);
void	rr_(t_data *data);

void 	rra_(t_data *data);
void	rrb_(t_data *data);
void	rrr_(t_data *data);


int		quick_sort(t_data *data);
int		is_chunk_sorted(t_data data, int start, int end);
int		initialise_chunks(t_data data, t_chunk **a, t_chunk **b);
int		push_chunk(t_chunk **head, int start, int end, int i);
int		*copyAndSort(t_data *data);
void	sort_arr(int *arr, int size);
int		pick_pivot(t_data data, int start, int end, int *push_num);
void	a_to_b(t_data *data, t_chunk **a, t_chunk **b);
void	b_to_a(t_data *data, t_chunk **a, t_chunk **b);


void	print_stack(t_data data);


#endif
