/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:46:20 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/10/16 13:16:20 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill(char *str, int dim, int n)
{
	unsigned int n2;

	n2 = 0;
	if (n < 0)
	{
		str[0] = '-';
		n2 = -n;
	}
	else
		n2 = n;
	while (n2)
	{
		str[dim -= 1] = (n2 % 10) + 48;
		n2 /= 10;
	}
}

static char	*zero(void)
{
	char	*str;

	if ((str = (char*)malloc(2 * sizeof(char))) == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static int	count(int dim, unsigned int n1)
{
	while (n1 /= 10)
		dim++;
	return (dim);
}

char		*ft_itoa(int n)
{
	unsigned int	n1;
	int				dim;
	char			*str;

	if (n == 0)
	{
		str = zero();
		return (str);
	}
	else if (n < 0)
	{
		dim = 2;
		n1 = -n;
	}
	else
	{
		dim = 1;
		n1 = n;
	}
	dim = count(dim, n1);
	if ((str = (char*)malloc((dim + 1) * sizeof(char))) == NULL)
		return (NULL);
	str[dim] = '\0';
	fill(str, dim, n);
	return (str);
}
