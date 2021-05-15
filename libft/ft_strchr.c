/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:32:57 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/10/14 16:21:03 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *str;
	char c1;

	str = (char*)s;
	c1 = (char)c;
	while (*str != '\0')
	{
		if (*str == c1)
			return ((char*)str);
		else
			str++;
	}
	if (c1 == '\0')
		return ((char*)str);
	return (0);
}
