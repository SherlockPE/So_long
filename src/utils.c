/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:44:22 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/19 11:59:36 by flopez-r         ###   ########.fr       */
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

void	check_extention(char *path)
{
	int i;
	int len;
	char *extention;
	len = ft_strlen(path);

	len -= 4;
	extention = ft_calloc(5, 1);
	if (!extention)
		ft_perror("Malloc error 🥁");
	i = 0;
	while (i < len && path[len])
	{
		extention[i]  = path[len];
		i++;
		len++;
	}
	if (ft_strncmp(extention, ".ber", ft_strlen(path)) != 0)
	{
		free(extention);
		extention = NULL;
		ft_perror("This extention is no valid for this proyect 😪");
	}
	free(extention);
	extention = NULL;
}
