/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:10:00 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/25 19:15:02 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algo(t_stack **a, t_stack **b)
{
	// push two elemetns and sort them in descending order
	pa_(b, a);
	pa_(b, a);
	if (is_sorted(*b))
		sa_(b);

	//-----------------
}