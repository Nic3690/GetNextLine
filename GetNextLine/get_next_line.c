/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:39:41 by nfurlani          #+#    #+#             */
/*   Updated: 2023/04/04 17:49:39 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *overflow)
{
	int		i;
	char	*str;

	i = 0;
	if (!overflow[i])
		return (NULL);
	while (overflow[i] != '\n' && overflow[i] != '\0')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (overflow[i] != '\n' && overflow[i] != '\0')
	{
		str[i] = overflow[i];
		i++;
	}
	if (overflow[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*temp;
	int			byte;
	static char	*overflow;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	byte = 1;
	while (byte != 0 && !ft_find_char(overflow, '\n'))
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte] = '\0';
		overflow = ft_strjoin(overflow, buff);
	}
	free(buff);
	temp = ft_get_line(overflow);
	overflow = ft_save_line(overflow);
	return (temp);
}

// int main()
// {
// 	int fd = open("prova.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	int i = 6;

// 	while (i > 0)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i--;
// 	}
// 	close(fd);
// }
