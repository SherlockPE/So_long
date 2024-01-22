/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:13:19 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/22 16:10:57 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

//A funçao lê um arquivo e retorna uma matriz no mapa
char	**create_map(char *path)
{
	char	**matrix;
	int		alto;
	int		i;
	int		fd;

	//Obtener file descriptor
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_perror("No se pudo abrir el archivo");
	//Darle tamaño al mapa
	alto = 32;
	matrix = (char **)ft_calloc(alto + 1, sizeof(char *));
	if (!matrix)
		ft_perror("Malloc error\n");
	//Llenar el mapa
	i = 0;
	while (1)
	{
		matrix[i] = get_next_line(fd);
		if (matrix[i] == 0)
			break ;
		i++;
	}
	return (matrix);
}

void	check_extention(char *path)
{
	int		i;
	int		len;
	char	*extention;

	len = ft_strlen(path);
	len -= 4;
	extention = ft_calloc(5, 1);
	if (!extention)
		ft_perror("Malloc error 🥁");
	i = 0;
	while (i < len && path[len])
	{
		extention[i] = path[len];
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

//Function prints an array of arrays (the map)
void	print_map(char **matrix)
{
	int		i;
	int		j;
	char	actual;

	ft_printf("-----------------------------------------------\n");
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			actual = ft_toupper(matrix[i][j]);
			if (actual == '1')
				ft_printf(BLUE"%c"RESET, actual);
			else if (actual == '0')
				ft_printf("%c", actual);
			else if (actual == 'P')
				ft_printf(RED"%c"RESET, actual);
			else if (actual == 'C')
				ft_printf(YELLOW"%c"RESET, actual);
			else if (actual == 'E')
				ft_printf(GREEN"%c"RESET, actual);
			else
				ft_printf("%c", actual);
			j++;
		}
		i++;
	}
	ft_printf("\n");
	ft_printf("-----------------------------------------------\n");
}
