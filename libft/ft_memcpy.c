/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:34:56 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/10/16 12:46:12 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	unsigned int	j;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	j = 0;
	while (j < n)
	{
		dst2[j] = src2[j];
		j++;
	}
	return (dst2);
}
