/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:27:20 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/05/30 21:52:01 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*my_strjoin(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		flag;

	buffer = (char *)malloc(2);
	if (!line || !buffer)
		return (-1);
	*line = (char *)malloc(1);
	*line[0] = '\0';
	flag = read(0, buffer, 1);
	while (flag > 0)
	{
		if (buffer[0] == '\n')
			break ;
		*line = my_strjoin(*line, buffer[0]);
		flag = read(0, buffer, 1);
	}
	free(buffer);
	return (flag);
}
