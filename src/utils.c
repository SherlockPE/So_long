/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:44:22 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/18 15:54:03 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_perror(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

//A funçao lê um arquivo e retorna uma matriz no mapa
char	**create_map(int fd)
{
	char	**matrix;
	int		alto;
	int		i;

	//Darle tamaño al mapa
	alto = 32;
	matrix = (char **)ft_calloc(alto + 1, sizeof(char *));

	//Llenar el mapa
	i = 0;
	while (i < alto)
	{
		matrix[i] = get_next_line(fd);
		i++;
	}
	return (matrix);
}
