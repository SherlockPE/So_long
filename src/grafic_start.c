/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/01 17:09:02 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

//Function starts
void	start_grafics(char **matrix, t_data *data)
{
	int	alto;
	int	ancho;

	alto = 0;
	ancho = (ft_strlen(matrix[0]) - 1);
	while (matrix[alto])
		alto++;
	data->g_data.mlx = mlx_init();
	if (!data->g_data.mlx)
		ft_perror("start grafics fucntion error");
	data->g_data.window = mlx_new_window(data->g_data.mlx, ancho * PIXEL_SIZE,
			alto * PIXEL_SIZE, "So_long");
	if (!data->g_data.window)
		ft_perror("Problemas al crear la ventana");
}

void	create_images(t_data *data)
{
	int	img_width;
	int	img_height;

	data->img_data.colectibles = mlx_xpm_file_to_image(data->g_data.mlx, \
		"./textures/colects.xpm", &img_width, &img_height);
	data->img_data.floor = mlx_xpm_file_to_image(data->g_data.mlx, \
		"./textures/floor.xpm", &img_width, &img_height);
	data->img_data.player = mlx_xpm_file_to_image(data->g_data.mlx, \
		"./textures/player.xpm", &img_width, &img_height);
	data->img_data.walls = mlx_xpm_file_to_image(data->g_data.mlx, \
		"./textures/walls.xpm", &img_width, &img_height);
	data->img_data.end = mlx_xpm_file_to_image(data->g_data.mlx, \
		"./textures/exit.xpm", &img_width, &img_height);
	if (!data->img_data.colectibles || !data->img_data.floor
		|| !data->img_data.player || !data->img_data.walls)
		ft_perror("create images function error");
	//mlx_destroy_image
}

void	search_player(t_data *data, char **map)
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
			{
				data->cords_player.x = j;
				data->cords_player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	put_background(t_data *data, char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map[i])
	{
		j = 0;
		c = map[i][j];
		c = ft_toupper(c);
		while (c != '\n' && c)
		{
			if (c == '1')
				put_img(data, data->img_data.walls, j, i);
			else if (c == '0')
				put_img(data, data->img_data.floor, j, i);
			else if (c == 'E')
				put_img(data, data->img_data.end, j, i);
			else if (c == 'C')
				put_img(data, data->img_data.colectibles, j, i);
			j++;
		}
		i++;
	}
}

void		deploy_playground(char **map, t_data *data)
{
	printf("Grafics ready LETSGO ");
	start_grafics(map, data);
	create_images(data);
	put_background(data, map);
	search_player(data, map);
	put_img(data, data->img_data.player, data->cords_player.x, data->cords_player.y);
}