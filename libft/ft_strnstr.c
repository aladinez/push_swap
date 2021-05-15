/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:38:25 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/10/17 15:30:59 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	unsigned long	j;
	unsigned long	i;
	unsigned long	save;

	j = 0;
	i = 0;
	if (needle[j] == '\0')
		return ((char*)hay);
	while (hay[i] != '\0')
	{
		save = i;
		while (hay[i] == needle[j] && i < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char*)hay + i - j + 1);
			i++;
		}
		j = 0;
		i = save + 1;
	}
	return (0);
}
