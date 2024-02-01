/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/01 20:06:59 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	put_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->g_data.mlx, data->g_data.window, img, x
		* PIXEL_SIZE, y * PIXEL_SIZE);
}

void	end_program(t_data *data)
{
	mlx_destroy_window(data->g_data.mlx, data->g_data.window);
	exit(0);
}

void	put_player(t_data *data)
{
	put_img(data, data->img_data.player, data->cords_player.x,
		data->cords_player.y);
}

void	reset_player(t_data *data, char **map)
{
	mlx_clear_window(data->g_data.mlx, data->g_data.window);
	put_background(data, map);
	put_player(data);
}

int	check_movement(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		return (0);
	if (data->map[y][x] == 'C')
	{
		data->n_mv += 1;
		data->n_col -= 1;
		data->map[y][x] = '0';
		return (1);
	}
	if (data->map[y][x] == '0')
	{
		data->n_mv += 1;
		return (1);
	}
	if (data->map[y][x] == 'E' && data->n_col == 0)
	{
		data->n_mv += 1;
		end_program(data);
		return (1);
	}
	return (0);
}


int	key_events(int keycode, t_data *data)
{
	printf("Keycode %d\n", keycode);
	if (keycode == UP_L || keycode == UP_D) //Up
	{
		if (check_movement(data, data->cords_player.x, data->cords_player.y - 1))
			data->cords_player.y -= 1;
	}
	else if (keycode == LEFT_L || keycode == LEFT_D) //Left
	{
		if (check_movement(data, data->cords_player.x - 1, data->cords_player.y))
			data->cords_player.x -= 1;
	}
	else if (keycode == DOWN_L || keycode == DOWN_D) //Down
	{
		if (check_movement(data, data->cords_player.x, data->cords_player.y + 1))
			data->cords_player.y += 1;
	}
	else if (keycode == RIGHT_L || keycode == RIGHT_D) //Right
	{
		if (check_movement(data, data->cords_player.x + 1, data->cords_player.y))
			data->cords_player.x += 1;
	}
	else if (keycode == ESC)
			end_program(data);
	reset_player(data, data->map);
	return (1);
}
