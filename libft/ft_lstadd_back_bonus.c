/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 23:17:01 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/10/25 00:51:45 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*plus;

	if (!(*alst))
	{
		ft_lstadd_front(alst, new);
		return ;
	}
	plus = ft_lstlast(*alst);
	plus->next = new;
}
