/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/29 12:50:15 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

//Function starts 
void    start_grafics(char **matrix, void **mlx, void **window)
{
	int		alto;
	int		ancho;

	alto = 0;
	ancho = ft_strlen(matrix[0]);
	while (matrix[alto])
		alto++;
	*mlx = mlx_init();
	if (!*mlx)
		ft_perror("start grafics fucntion error");
	*window = mlx_new_window(*mlx, ancho * PIXEL_SIZE, alto * PIXEL_SIZE, "So_long");
	if (!*window)
		ft_perror("Problemas al crear la ventana");
}

void	create_images(img_game *img_dta, grafic_init init)
{
	// void	*img;
	int img_width;
	int img_height;

	// img_dta.colectibles = 0;
	// img_dta.floor = 0;
	// img_dta.player = 0;
	// img_dta.walls = 0;

	img_dta->colectibles = mlx_xpm_file_to_image(init.mlx, "./textures/coin.xpm", &img_width, &img_height);
	img_dta->floor = mlx_xpm_file_to_image(init.mlx, "./textures/pasto.xpm", &img_width, &img_height);
	img_dta->player = mlx_xpm_file_to_image(init.mlx, "./textures/monigote.xpm", &img_width, &img_height);
	img_dta->walls = mlx_xpm_file_to_image(init.mlx, "./textures/ladrillos.xpm", &img_width, &img_height);

	if (!img_dta->colectibles || !img_dta->floor || !img_dta->player || !img_dta->walls)
		ft_perror("create images function error");
}
// void	*create_images(void	*mlx, char *path)
// {
// 	void	*img;
// 	int img_width;
// 	int img_height;


// 	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
// 	if (!img)
// 		ft_perror("create images function error");
// 	return (img);
// }

void	put_images(void *mlx, void *mlx_window, img_game img_data)
{
	mlx_put_image_to_window(mlx, mlx_window, img_data.player, 0, 0);
}