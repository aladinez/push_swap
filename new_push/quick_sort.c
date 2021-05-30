/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:43:38 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 16:57:45 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap1.h"







int quick_sort(t_data *data)
{
    t_chunk *A_chunks;
    t_chunk *B_chunks;
	
	if (!initialise_chunks(*data, &A_chunks, &B_chunks))
		return (ERROR);
    while (1)
    {
        if (A_chunks->status == SORTED && !B_chunks)
            break ;
        else if (A_chunks->status == SORTED)
            b_to_a(data, &B_chunks, &A_chunks);
        else
            a_to_b(data, &A_chunks, &B_chunks);
    }
	free_chunks(&A_chunks);
	return (SUCCESS);
}
