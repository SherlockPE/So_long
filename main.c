/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:08:00 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/01 12:23:29 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pruebas.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;

	int		x_player;
	int		y_player;
}			t_data;

typedef struct s_img_dta
{
	void	*player;
	void	*wall;
	void	*floor;
}			t_img_data;

void	put_image(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img_wall, x
			* PIXEL_SIZE, y * PIXEL_SIZE);
}

int	key_event(int keycode, t_data *data)
{
	printf("Key code: %d\n", keycode);
	if (keycode == 0 || keycode == 124)
	{
		data->x_player++;
		put_image(data, data->x_player, data->y_player);
	}
	return (0);
}

void	put_background(t_data *data)
{
	int i;
	int j;

	i = 7;
	while (i)
	{
		j = 7;
		while (j)
		{
			
		}
		
	}
}

void	get_images(t_data *data, t_img_data *img_data)
{
	int	width;
	int	heigth;

	img_data->floor = mlx_xpm_file_to_image(data->mlx, "floor.xpm", &width,
			&heigth);
	img_data->player = mlx_xpm_file_to_image(data->mlx, "player.xpm", &width,
			&heigth);

	if (!img_data->floor || !img_data->player)
	{
		printf("Imagen no valida/encontrada!\n");
		return (1);
	}
}

int	main(void)
{
	t_data		data;
	t_img_data	img_data;
	int			width;
	int			heigth;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 448, 448, "Hola, esto es una prueba");
	get_images(&data, &img_data);

	put_background(&img_data);
	data.x_player = 0;
	data.y_player = 0;
	put_image(&data, 0, 0);
	mlx_key_hook(data.win, key_event, &data);
	mlx_loop(data.mlx);
	return (0);
}
