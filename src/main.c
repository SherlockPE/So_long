/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:15:36 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/18 15:39:20 by flopez-r         ###   ########.fr       */
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

//Checker 1 (el mapa debe ser cuadrilatero)
void	check_quadrilateral(char **map)
{
	int	i;
	int	width;
	int	first_width;

	i = 0;
	first_width = 0;

	//Achar o primeiro comprimento
	while (map[i][first_width] != '\n')
		first_width++;

	/* ft_printf("El ancho del mapa es: %d\n", first_width); */
	//Verificar que o mapa é um quadrilátero
	while (map[++i])
	{
		width = 0;
		while (map[i][width] != '\n' && map[i][width])
			width++;
		/* ft_printf("Ancho conseguido en la posición %d: %d\n", i, width); */
		if (width != first_width)
			ft_perror("Map must be quadrilateral");
	}
}

//Checker 2 (el mapa debe estar dentro de paredes)
void	check_is_inside_walls(char	**map)
{
	int	i;
	int	width;

	//Achar o primeiro comprimento (1)
	//E comprovar o primeira fila
	i = 0;
	width = 0;
	while (map[i][width] != '\n')
	{
		if (map[i][width] != '1')
			ft_perror("Map must be inside walls");
		width++;
	}

	//Verificar as beiras (2)
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			ft_perror("Map must be inside walls");
		i++;
	}

	//Verificar na ultima linea
	i -= 1;
	width = 0;
	while (map[i][width])
	{
		if (map[i][width] != '1')
			ft_perror("Map must be inside walls");
		width++;
	}
}

// void	check_valid_exit(matrix)
// {
	
// }

//A funçao verifica se um mapa é valido
void	check_map(char *path)
{
	char	**matrix;
	int		fd;

	fd = open(path, O_RDONLY);
	//Chequear si el path es valido

	//Get map
	matrix = create_map(fd);

	//Imprimir mapa
	int	i = 0;
	while (matrix[i])
	{
		ft_printf("%s", matrix[i]);
		i++;
	}
	ft_printf("\n");

	//Checkers
	check_quadrilateral(matrix);//Done
	check_is_inside_walls(matrix);//Done
	// check_valid_exit(matrix);
	
}

int	main(int argc, char *argv[])
{
	if (argc <= 1)
		ft_perror("Arguments not valid");

	check_map(argv[1]);
	ft_printf("O MAPA ESTA BEM");
	return (0);
}
