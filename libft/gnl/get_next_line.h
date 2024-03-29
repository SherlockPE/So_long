/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:41:29 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/01/17 16:03:16 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
size_t	ft_strlen_gnl(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc_gnl(size_t count, size_t size);

#endif