/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:50:02 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/10/22 18:21:21 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst1;

	if (!lst)
		return (NULL);
	lst1 = lst;
	while (lst1->next)
	{
		lst1 = lst1->next;
	}
	return (lst1);
}
