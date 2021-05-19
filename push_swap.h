#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"



typedef struct s_stack {
    int data;
    struct s_stack *next;
}t_stack;

void	push(t_stack** root, int data);
int		is_dupp(t_stack *root);
int		is_sorted(t_stack *root);
int		is_number(char *str);
int		check_args(char **str, t_stack **root);
void	free_stack(t_stack **head);

void	_s(t_stack **head_ref);
void	_ss(t_stack **a, t_stack **b);
void	_p(t_stack **a, t_stack **b);
void	_r(t_stack **head);
void	print_stack(t_stack *head);

#endif
