/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:37:38 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/21 17:34:07 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// Function count how many collectionables are in the map
// And found the cordinates of the player
int	count_col_and_check_cords(char **map, int *col, int *cords_P)
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
			if (ft_toupper(map[i][j]) == 'P')
			{
				cords_P[0] = i;
				cords_P[1] = j;
			}
			j++;
		}
		i++;
	}
	return (*col);
}

//Function gets 
void	discount_values(char actual_pos, int *col, int *end)
{
	actual_pos = ft_toupper(actual_pos);
	if (actual_pos == 'C')
		(*col)--;
	else if (actual_pos == 'E')
		(*end)--;
}

int	drop_water(char **map, int *cords, int *col, int *end)
{
	int		sum_i;
	int		sum_j;
	char	actual_pos;

	sum_i = -1;
	actual_pos = map[cords[0]][cords[1]];
	discount_values(actual_pos, col, end);
	if (*col == 0 && end == 0)
		return (1);
	ft_printf("\n--------------Check water function-----------\n");
	while (sum_i <= 1)
	{
		sum_j = -1;
		while (sum_j <= 1)
		{
			actual_pos = map[cords[0] + sum_i][cords[1] + sum_j];
			ft_printf("%c", actual_pos);
			sum_j++;
		}
		sum_i++;
		ft_printf("\n");
	}
	return (0);
}

// Principal function
void	check_valid_exit(char **map)
{
	int	col;
	int	end;
	int	cords_player[2];

	end = 0;
	count_col_and_check_cords(map, &col, cords_player);
	ft_printf("\nCantidad de coleccionables: %d\n", col);
	ft_printf("\nPlayer is in (%d, %d)", cords_player[0], cords_player[1]);
	// ft_printf("\n%c\n", map[cords_player[0]][cords_player[1]]);
	if (!drop_water(map, cords_player, &col, &end))
		ft_perror(RED"The actual map, doesnt have a valid exit"RESET);
}
