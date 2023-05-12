/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:39:41 by nfurlani          #+#    #+#             */
/*   Updated: 2023/04/04 18:29:08 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*overflow[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	byte = 1;
	while (byte != 0 && !ft_find_char(overflow[fd], '\n'))
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte] = '\0';
		overflow[fd] = ft_strjoin(overflow[fd], buff);
	}
	free(buff);
	temp = ft_get_line(overflow[fd]);
	overflow[fd] = ft_save_line(overflow[fd]);
	return (temp);
}

// int main()
// {
// 	int fd1 = open("prova.txt", O_RDONLY);
//     int fd2 = open("boh.txt", O_RDONLY);
//     int fd3 = open("tutti.txt", O_RDONLY);
// 	char *line = get_next_line(fd1);
// 	printf("%s", line);
// 	line = get_next_line(fd2);
// 	printf("%s", line);
// 	line = get_next_line(fd3);
// 	printf("%s", line);
// 	line = get_next_line(fd1);
// 	printf("%s", line);
// 	free(line);
// 	int i = 6;

// 	while (i > 0)
// 	{
// 		line = get_next_line(fd1);
// 		printf("%s", line);
// 		free(line);
// 		i--;
// 	}
// 	close(fd1);
//     close(fd2);
//     close(fd3);
// }
