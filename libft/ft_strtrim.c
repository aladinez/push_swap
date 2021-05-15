/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 22:44:08 by aez-zaou          #+#    #+#             */
/*   Updated: 2019/10/24 23:40:20 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char const *set, char c)
{
	int i;

	i = 0;
	while (set && set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	if (!s1)
		return (NULL);
	while (check(set, s1[i]))
		i++;
	if (i == ft_strlen(s1))
	{
		if ((str = (char*)malloc(sizeof(char))) == NULL)
			return (0);
		str[0] = '\0';
		return (str);
	}
	j = ft_strlen(s1) - 1;
	while (check(set, s1[j]))
		j--;
	if ((str = (char*)malloc((j - i + 2) * sizeof(char))) == NULL)
		return (0);
	ft_strlcpy(str, s1 + i, j - i + 2);
	return (str);
}
