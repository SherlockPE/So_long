/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:42:25 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/18 16:17:26 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

//Checker 1 (el mapa debe ser cuadrilatero)
static void	check_quadrilateral(char **map)
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
static void	check_is_inside_walls(char	**map)
{
	int	i;
	int	width;

	//Achar o primeiro comprimento (1)
	//E comprovar a primeira fila
	i = 0;
	width = 0;
	while (map[i][width] != '\n')
	{
		if (map[i][width] != '1')
			ft_perror("Map must be inside walls 🏰");
		width++;
	}

	//Verificar as beiras (2)
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			ft_perror("Map must be inside walls 🏰");
		i++;
	}

	//Verificar na ultima linea
	i -= 1;
	width = 0;
	while (map[i][width])
	{
		if (map[i][width] != '1')
			ft_perror("Map must be inside walls 🏰");
		width++;
	}
}

//A funçao verifica se um mapa é valido
void	check_map(char **matrix)
{
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