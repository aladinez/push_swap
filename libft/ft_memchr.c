/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 23:32:21 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/10/15 20:16:00 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c1;
	unsigned int	i;

	str = (unsigned char*)s;
	c1 = (unsigned char)c;
	i = 0;
	while (n)
	{
		if (str[i] == c1)
			return ((unsigned char*)s + i);
		else
		{
			i++;
			n--;
		}
	}
	return (0);
}
