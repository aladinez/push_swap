/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:07:51 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/26 15:53:00 by aez-zaou         ###   ########.fr       */
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
}t_data;

int		is_number(char *str);
void	print_nums(t_data data);
int		check_args(char **str, t_data *data);
void	num_join(t_data *data, int num);
void	free_data(t_data *data);
int		is_A_sorted(t_data data);




#endif
