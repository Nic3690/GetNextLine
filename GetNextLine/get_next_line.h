/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:19:45 by nfurlani          #+#    #+#             */
/*   Updated: 2023/04/04 17:09:55 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_find_char(char *buff, char c);
char	*ft_save_line(char *temp);
char	*ft_get_line(char *overflow);
char	*get_next_line(int fd);

#endif