/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:42:25 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/22 18:55:01 by flopez-r         ###   ########.fr       */
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
			ft_perror("Map must be quadrilateral 🟥");
	}
}

//Checker 2 (el mapa debe estar dentro de paredes)
static void	check_is_inside_walls(char **map)
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
			ft_perror("The last line of the must be an entire wall🏰");
		width++;
	}
}

//Checker 3 (El mapa debe tener:
//	1) No más de 1 End
//	2) Solo 1 Player)
void	check_EPC_ocurrences(char c, int *j, int last)
{
	static int	p;
	static int	e;
	static int	col;

	if (c == 'P')
		p++;
	else if (c == 'C')
		col++;
	else if (c == 'E')
		e++;
	if (p > 1)
		ft_perror("Map canoot have more than 1 player inside ");
	if (e > 1)
		ft_perror("Map can't have more than 1 exit inside");
	if (last)
	{
		if (p < 1)
			ft_perror("Map need at least 1 player inside");
		if (e < 1)
			ft_perror("Map must have 1 exit");
		if (col <= 0)
			ft_perror("Map must have 1 colleccionable ");
	}
	(*j)++;
}

//Checker 4 (El mapa solo debe tener los caracteres "1, 0, E, P, C")
void	check_cells(char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			c = ft_toupper(c);
			if (c == '1' || c == '0' || c == '\n')
				j++;
			else if (c == 'E' || c == 'P' || c == 'C')
				check_EPC_ocurrences(c, &j, 0);
			else
				ft_perror("Caracteres el mapa no soportados 🚷");
		}
		i++;
	}
	check_EPC_ocurrences('A', &j, 1);
}

//A funçao verifica se um mapa é valido
void	check_map(char **matrix)
{
	//If the map doesnt have anything the program exit withs error
	if (!matrix[0])
	{
		free_map(matrix);
		ft_perror("Mapa no valido 🍙");
	}
	//Checkers
	check_quadrilateral(matrix);   //1 Done
	check_is_inside_walls(matrix); //2 Done
	check_cells(matrix);           //3 Done
	check_valid_exit(matrix);      //4 Done
}
