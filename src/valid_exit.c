/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:37:38 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/22 17:43:59 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// Function count how many collectionables are in the map
int	count_collectibles(char **map, int *col)
{
	int	i;
	int	j;

	i = 0;
	*col = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_toupper(map[i][j]) == 'C')
				(*col)++;
			j++;
		}
		i++;
	}
	return (*col);
}

//Function Discount the value of collectibles and END
void	discount_values(char actual_pos, int *col, int *end)
{
	if (actual_pos == 'C')
		(*col)--;
	else if (actual_pos == 'E')
		(*end)--;
	if (*col == 0 && *end == 0)
		return ;
	// ft_perror("El mapa no es jugable ⛹️‍♂️");
}

//Function looks for "0, E, C" characters and transforms to a P
int	expand_players(char **map, int i, int j)
{
	char	actual;

	actual = map[i][j];
	if (actual == '1')
		return (0);
	//Down
	if (map[i + 1][j] == 'P')
		map[i][j] = 'P';
	//Left
	else if (map[i][j - 1] == 'P')
		map[i][j] = 'P';
	//Right
	else if (map[i][j + 1] == 'P')
		map[i][j] = 'P';
	//Up
	else if (map[i - 1][j] == 'P')
		map[i][j] = 'P';
	if (map[i][j] == 'P')
		return (1);
	return (0);
}


//Function replicates the character P if they found around a P character
void	look_for_players(char **map, int *col, int *end)
{
	int		i;
	int		j;
	char	cycle;
	char	actual;

	cycle = 1;
	while (cycle)
	{
		cycle = 0;
		i = 1;
		while (map[i])
		{
			j = 1;
			while (map[i][j])
			{
				actual = ft_toupper(map[i][j]);
				// if (discount_values(actual, col, end))
				// 	return ;
				if (expand_players(map, i, j))
					cycle = 1;
				else
					discount_values(actual, col, end);
				j++;
			}
			i++;
		}
	}
}

//	Checker 4 (El mapa debe ser jugable)
void	check_valid_exit(char **map)
{
	int		col;
	int		end;
	char	**map_copy;

	end = 1;
	//Count how many collectionables are in the map
	count_collectibles(map, &col);
	ft_printf("Cantidad de coleccionables: %d\n", col);
	
	print_map(map);
	//Expand player if they are in a "0, C, E"
	map_copy = map;
	look_for_players(map_copy, &col, &end);
	if (col != 0 || end != 0)
		ft_perror("El mapa no es jugable ⛹️‍♂️");

	print_map(map);
	ft_printf("Cantidad de coleccionables: %d\n", col);
}
