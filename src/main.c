/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:15:36 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/19 12:20:01 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int argc, char *argv[])
{
	char	**matrix;

	//Check arguments
	if (argc <= 1)
		ft_perror("Arguments not valid");

	//Check extention
	check_extention(argv[1]);

	//Get map
	matrix = create_map(argv[1]);

	//Check if map is ok
	check_map(matrix);

	//free map
	/* crear funcion para liberar el mapa */

	ft_printf("\nMAP IS OK ✅\n");
	return (0);
}
