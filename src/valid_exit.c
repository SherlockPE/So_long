/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:37:38 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/23 12:34:30 by flopez-r         ###   ########.fr       */
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

//Function looks for "0, E, C" characters and transforms to a P
int	expand_players(char **map, int i, int j, int *col)
{
	char	actual;

	actual = map[i][j];
	if (actual == '1' || actual == 'E' || actual == 'P')
		return (0);
	//Down and Left
	if (map[i + 1][j] == 'P' || map[i][j - 1] == 'P')
		map[i][j] = 'P';
	//Right and Up
	else if (map[i][j + 1] == 'P' || map[i - 1][j] == 'P')
		map[i][j] = 'P';
	//If Expands
	if (map[i][j] == 'P')
	{
		//If collectiona
		if (actual == 'C')
			(*col)--;
		return (1);
	}
	return (0);
}

int	check_exit_corners(char **map, int *end)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				if (map[i + 1][j] == 'P' || map[i][j - 1] == 'P')
				{
					(*end)--;
					return (0);
				}
				else if (map[i][j + 1] == 'P' || map[i - 1][j] == 'P')
				{
					(*end)--;
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

//Function replicates the character P if they found around a P character
void	look_for_players(char **map, int *col, int *end)
{
	int		i;
	int		j;
	char	cycle;

	cycle = 1;
	while (cycle && ((*col) || check_exit_corners(map, end)))
	{
		cycle = 0;
		i = 1;
		while (map[i])
		{
			j = 1;
			while (map[i][j])
			{
				map[i][j] = ft_toupper(map[i][j]);
				if (expand_players(map, i, j, col))
					cycle = 1;
				j++;
			}
			// print_map(map);
			i++;
		}
	}
}


//	Checker 4 (El mapa debe ser jugable)
void	check_valid_exit(char *path)
{
	int		col;
	int		end;
	char	**map;

	//Get a new map 
	map = create_map(path);

	end = 1;
	//Count how many collectionables are in the map
	count_collectibles(map, &col);
	ft_printf("Cantidad de col: %d\n", col);

	//Expand player if they are in a "0, C, E"
	look_for_players(map, &col, &end);
	
	//Free the copy of the map 
	print_map(map);
	free_map(map);
	
	//Check if the path is valid
	if (col != 0 || end != 0)
		ft_perror("El mapa no es jugable ⛹️‍♂️");

	//Print cant od collectibles
	ft_printf("Cantidad de col after water: %d\n", col);
}
