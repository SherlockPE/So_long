/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:15:36 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/29 12:45:55 by flopez-r         ###   ########.fr       */
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
	grafic_init	inicializer;
	img_game	images_data;

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


	//NEW IMPLEMENTATION !!!!!!!
	//Create image
	create_images(&images_data, inicializer);

	//put image
	put_images(inicializer.mlx, inicializer.window, images_data);

	
	//OLD PART !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// //Create image
	// void	*img = create_images(inicializer.mlx, "./textures/monigote.xpm");//In progress

	// //put image
	// put_images(inicializer.mlx, inicializer.window, img);
	mlx_loop(inicializer.mlx);

	free_map(matrix);
	return (0);
}
