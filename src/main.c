/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:15:36 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/29 18:50:30 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	detect_leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char *argv[])
{
	// void	*mlx;
	char	**matrix;
	t_grafic_init	inicializer;
	t_img_game	images_data;

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

	//GRAFICS		 								<------SECOND PART IN PROGRESS
	start_grafics(matrix, &inicializer.mlx, &inicializer.window); //Done

	//Create image
	create_images(&images_data, inicializer);
	put_background(inicializer, images_data, matrix);
	put_cosas(inicializer, images_data, matrix);

	mlx_loop(inicializer.mlx);

	free_map(matrix);
	return (0);
}
