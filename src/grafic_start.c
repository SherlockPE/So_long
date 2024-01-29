/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/29 18:51:14 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

//Function starts 
void    start_grafics(char **matrix, void **mlx, void **window)
{
	int		alto;
	int		ancho;

	alto = 0;
	ancho = (ft_strlen(matrix[0]) - 1);
	while (matrix[alto])
		alto++;
	*mlx = mlx_init();
	if (!*mlx)
		ft_perror("start grafics fucntion error");
	*window = mlx_new_window(*mlx, ancho * PIXEL_SIZE, alto * PIXEL_SIZE, "So_long");
	if (!*window)
		ft_perror("Problemas al crear la ventana");
}

void	create_images(t_img_game *img_dta, t_grafic_init init)
{
	int img_width;
	int img_height;

	img_dta->colectibles = mlx_xpm_file_to_image(init.mlx, "./textures/coin.xpm", &img_width, &img_height);
	img_dta->floor = mlx_xpm_file_to_image(init.mlx, "./textures/pasto.xpm", &img_width, &img_height);
	img_dta->player = mlx_xpm_file_to_image(init.mlx, "./textures/monigote.xpm", &img_width, &img_height);
	img_dta->walls = mlx_xpm_file_to_image(init.mlx, "./textures/ladrillos.xpm", &img_width, &img_height);
	img_dta->end = mlx_xpm_file_to_image(init.mlx, "./textures/exit.xpm", &img_width, &img_height);

	if (!img_dta->colectibles || !img_dta->floor || !img_dta->player || !img_dta->walls)
		ft_perror("create images function error");
}

void	put_img(t_grafic_init init, void *img, int x, int y)
{
	mlx_put_image_to_window(init.mlx, init.window, img, x, y);
}

void	put_cosas(t_grafic_init init, t_img_game img_data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				put_img(init, img_data.player, j * PIXEL_SIZE, i * PIXEL_SIZE);
			else if (map[i][j] == 'E')
				put_img(init, img_data.end, j * PIXEL_SIZE, i * PIXEL_SIZE);
			else if (map[i][j] == 'C')
				put_img(init, img_data.colectibles, j * PIXEL_SIZE, i * PIXEL_SIZE);
			j++;
		}
		i++;
	}
}

void	put_background(t_grafic_init init, t_img_game img_data, char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			if (map[i][j] == '1')
				put_img(init, img_data.walls, j * PIXEL_SIZE, i * PIXEL_SIZE);
			else if (map[i][j] == '0' || map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
				put_img(init, img_data.floor, j * PIXEL_SIZE, i * PIXEL_SIZE);
			j++;
		}
		i++;
	}
}
