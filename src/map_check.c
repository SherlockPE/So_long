/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:42:25 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/04 11:54:35 by flopez-r         ###   ########.fr       */
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
	while (map[i][first_width] != '\n')
		first_width++;
	if (first_width >= 40)
		ft_perror("El mapa es demasiado grande (height>=21)");
	while (map[++i])
	{
		width = 0;
		while (map[i][width] != '\n' && map[i][width])
			width++;
		if (width != first_width)
			ft_perror("Map must be quadrilateral 🟥");
		if (i >= 30)
		{
			ft_printf("Ancho: %d\n");
			ft_perror("El mapa es demasiado grande (widht >= 20)");
		}
	}
}

//Checker 2 (el mapa debe estar dentro de paredes)
static void	check_is_inside_walls(char **map)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (map[i][width] != '\n')
	{
		if (map[i][width] != '1')
			ft_perror("Map must be inside walls 🏰");
		width++;
	}
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			ft_perror("Map must be inside walls 🏰");
		i++;
	}
	i -= 1;
	width = 0;
	while (map[i][width])
	{
		if (map[i][width] != '1')
			ft_perror("The last line of the must be an entire wall🏰");
		width++;
	}
}

//Checker 3 (Map must be:
//	1) Only 1 end
//	2) Only 1 player)
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

//Checker 4 (El mapa solo debe tener los caracteres "1, 0, E, P, C") && "N"
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
			if (c == '1' || c == '0' || c == '\n' || c == 'N')
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
//If the map doesnt have anything the program exit withs error
void	check_map(char **matrix)
{
	if (!matrix[0])
	{
		free_map(matrix);
		ft_perror("Mapa no valido 🍙");
	}
	check_quadrilateral(matrix);
	check_is_inside_walls(matrix);
	check_cells(matrix);
}
