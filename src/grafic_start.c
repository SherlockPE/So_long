/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/26 17:46:53 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

//Function starts 
void    start_grafics(char **matrix, void **start, void **window)
{
	int		alto;
	int		ancho;

	alto = 0;
	ancho = ft_strlen(matrix[0]);
	while (matrix[alto])
		alto++;
	*start = mlx_init();
	if (!*start)
		ft_perror("Start grafics fucntion error");
	*window = mlx_new_window(*start, ancho * PIXEL_SIZE, alto * PIXEL_SIZE, "So_long");
	if (!*window)
		ft_perror("Problemas al crear la ventana");
}

void	*create_images(void	*mlx, char *path)
{
	void	*img;
	int img_width;
	int img_height;


	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	if (!img)
		ft_perror("create images function error");
	return (img);
}

void	put_images(void *mlx, void *mlx_window, void *img)
{
	(void)mlx;
	(void)mlx_window;
	(void)img;
	mlx_put_image_to_window(mlx, mlx_window, img, 0, 0);
}