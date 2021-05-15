/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:37:38 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/10/14 16:17:33 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *str;
	char *str2;
	char c1;

	str = (char*)s;
	c1 = (char)c;
	str2 = 0;
	while (*str != '\0')
	{
		if (*str == c1)
		{
			str2 = str;
			str++;
		}
		else
			str++;
	}
	if (c1 == '\0')
		return ((char*)str);
	return ((char*)str2);
}
