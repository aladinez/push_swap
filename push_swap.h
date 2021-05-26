/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:07:51 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/26 14:08:16 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"



typedef struct s_stack {
    int data;
    struct s_stack *next;
}t_stack;



void	push(t_stack** root, int data);
void	push_back(t_stack** root, int data);
int		is_dupp(t_stack **root);
int		is_sorted(t_stack *root);
int		is_number(char *str);
int		check_args(char **str, t_stack **root);
void	free_stack(t_stack **head);

void	sa_(t_stack **head_ref);
void	ss_(t_stack **a, t_stack **b);
void	pa_(t_stack **a, t_stack **b);
void	ra_(t_stack **head);
void	rr_(t_stack **a, t_stack **b);
void	rra_(t_stack **head);
void	rrr_(t_stack **a, t_stack **b);
void	print_stack(t_stack *head);
int		run_instruction(char *str, t_stack **a, t_stack **b);
int		my_strcmp(char *str1, char *str2);
void	sort_algo(t_stack **a, t_stack **b);


#endif
