/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:37:38 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/20 19:04:14 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

//Function count how many collectionables are in the map
//And found the cordinates of the player
int	count_cols(char **map, int *col, int *cords_P)
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

//Principal function
void    check_valid_exit(char **map)
{
	int	col;
	int	cords_player[2];

	count_cols(map, &col, cords_player);
	ft_printf("\nCantidad de coleccionables: %d\n", col);
	ft_printf("\nPlayer is in (%d, %d)", cords_player[0], cords_player[1]);
	ft_printf("\n%c\n", map[cords_player[0]][cords_player[1]]);

	
}
