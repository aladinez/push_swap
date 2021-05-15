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

#endif