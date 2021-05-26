/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:07:51 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/26 20:47:11 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"


typedef struct s_data {
	int		*stack;
	int		size;
	int		b_index;
}t_data;

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


void	print_stack(t_data data);


#endif
