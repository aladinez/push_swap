/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:10:26 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/10/16 23:01:02 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst2;
	const char	*src2;

	dst2 = (char*)dst;
	src2 = (const char*)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len)
		{
			dst2[len - 1] = src2[len - 1];
			len--;
		}
	}
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return ((unsigned char*)dst);
}
