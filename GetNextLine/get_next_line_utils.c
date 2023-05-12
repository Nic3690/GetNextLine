/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:42:12 by nfurlani          #+#    #+#             */
/*   Updated: 2023/04/04 17:54:08 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

int	ft_find_char(char *buff, char c)
{
	int	i;

	i = 0;
	if (!buff)
		return (0);
	while (buff[i] != '\0')
	{
		if (buff[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_save_line(char *overflow)
{
	char	*str;
	int		i;
	int		point;

	i = 0;
	point = 0;
	while (overflow[i] != '\0' && overflow[i] != '\n')
		i++;
	if (!overflow[i])
	{
		free(overflow);
		return (NULL);
	}
	str = malloc(ft_strlen(overflow) - i + 1);
	if (!str)
		return (NULL);
	point = i + 1;
	i = 0;
	while (overflow[point] != '\0')
		str[i++] = overflow[point++];
	str[i] = '\0';
	free(overflow);
	return (str);
}
