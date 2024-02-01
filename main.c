/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:08:00 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/01 14:17:04 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pruebas.h"

void	set_background(t_data 	*data)
{
	int	i;
	int	j;

	i = 7;
	while (i--)
	{
		j = 7;
		while (j--)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->floor, j * PIXEL_SIZE, i * PIXEL_SIZE);
		}
	}
}

void	get_images(t_data *data)
{
	int	width;
	int	height;
	data->player = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm", &width, &height);
	data->walls = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm", &width, &height);
	data->floor = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm", &width, &height);
	if (!data->player || !data->walls || !data->floor)
	{
		printf("Fallo al crear una imagen");
		exit(1);
	}
}


void	put_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->player, data->x_cords * PIXEL_SIZE, data->y_cords * PIXEL_SIZE);
}


void	reset_player(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	set_background(data);
	put_player(data);
}

void	end_program(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	// mlx_destroy_image(data->mlx, data->player);
}

int	move_player(int keycode, t_data *data)
{
	printf("Keycode %d\n", keycode);
	if (keycode == UP_L || keycode == UP_D)//Up
		data->y_cords -= 1;
	else if (keycode == LEFT_L || keycode == LEFT_D)//Left
		data->x_cords--;
	else if (keycode == DOWN_L || keycode == DOWN_D)//Down
		data->y_cords++;
	else if (keycode == RIGHT_L || keycode == RIGHT_D)//Right
		data->x_cords++;
	else if (keycode == ESC)
		end_program(data);
	reset_player(data);
	return (1);
}


int	main(void)
{
	t_data	data;

	data.mlx = mlx_init(data.mlx);
	data.win = mlx_new_window(data.mlx, 7 * PIXEL_SIZE, 7 * PIXEL_SIZE, "Prueba de movimiento");
	
	get_images(&data);

	set_background(&data);

	//Set cords
	data.x_cords = 0;
	data.y_cords = 0;
	
	put_player(&data);
	mlx_key_hook(data.win, move_player, &data);



	mlx_loop(data.mlx);
}