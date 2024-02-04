/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/04 13:08:32 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	put_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->g_data.mlx, data->g_data.window, img, x
		* PIXEL_SIZE, y * PIXEL_SIZE);
}

void	put_player(t_data *data)
{
	put_img(data, data->img_data.player, data->cords_p.x,
		data->cords_p.y);
}

void	reset_player(t_data *data, char **map)
{
	mlx_clear_window(data->g_data.mlx, data->g_data.window);
	put_background(data, map);
	put_player(data);
}

void	error_create_img(t_data *data)
{
	if (!data->img_data.colectibles || !data->img_data.floor
		|| !data->img_data.player || !data->img_data.walls
		|| !data->img_data.end || !data->img_data.player2
		|| !data->img_data.enemies || !data->img_data.enemies2)
	{
		ft_printf(RED"Error ❌\n"RESET);
		ft_printf(RED"create images function error"RESET);
		end_program(data, EXIT_FAILURE);
	}
}

void	put_mc_to_win(t_data *data, char c, int x, int y)
{
	if (c == '1')
		put_img(data, data->img_data.walls, x, y);
	if (c == '0' || c == 'P' || c == 'E' || c == 'C' || c == 'N')
		put_img(data, data->img_data.floor, x, y);
	if (c == 'N')
		put_img(data, data->img_data.enemies, x, y);
	if (c == 'E')
		put_img(data, data->img_data.end, x, y);
	else if (c == 'C')
		put_img(data, data->img_data.colectibles, x, y);
}
