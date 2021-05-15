/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:09:16 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/10/22 18:28:33 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *jdida;
	t_list *tmp;
	t_list *tmp1;

	if (!lst || !f || !del)
		return (NULL);
	jdida = NULL;
	tmp = lst;
	jdida = ft_lstnew(f(tmp->content));
	tmp1 = jdida;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp)
		{
			tmp1->next = ft_lstnew(f(tmp->content));
			if (tmp1->next->content != f(tmp->content))
			{
				ft_lstclear(&jdida, del);
				return (NULL);
			}
			tmp1 = tmp1->next;
		}
	}
	return (jdida);
}
