/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:15:36 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/23 16:51:06 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	detect_leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char *argv[])
{
	char	**matrix;

	// atexit(detect_leaks);
	//MAP											<------FIRST PART DONE
	//Check arguments
	if (argc <= 1)
		ft_perror("Arguments not valid");

	//Check extention 1
	check_extention(argv[1]);

	//Get map
	matrix = create_map(argv[1]);

	//Print map
	print_map(matrix);

	//Checkers 1 2 3 4
	check_map(matrix);
	check_valid_exit(argv[1]);	//4 Done
	ft_printf(GREEN "\nMAP IS OK ✅\n"RESET);

	//GRAFICS										<------SECOND PART IN PROGRESS
	// print_window();

	free_map(matrix);
	return (0);
}
