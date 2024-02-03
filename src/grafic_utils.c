/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/03 14:06:24 by flopez-r         ###   ########.fr       */
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
	if (data->img_data.colectibles)
		mlx_destroy_image(data->g_data.mlx, data->img_data.colectibles);
	if (data->img_data.end)
		mlx_destroy_image(data->g_data.mlx, data->img_data.end);
	if (data->img_data.enemies)
		mlx_destroy_image(data->g_data.mlx, data->img_data.enemies);
	if (data->img_data.enemies)
		mlx_destroy_image(data->g_data.mlx, data->img_data.enemies2);
	if (data->img_data.floor)
		mlx_destroy_image(data->g_data.mlx, data->img_data.floor);
	if (data->img_data.player)
		mlx_destroy_image(data->g_data.mlx, data->img_data.player);
	if (data->img_data.player2)
		mlx_destroy_image(data->g_data.mlx, data->img_data.player2);
	if (data->img_data.walls)
		mlx_destroy_image(data->g_data.mlx, data->img_data.walls);
	mlx_destroy_window(data->g_data.mlx, data->g_data.window);
	free_map(data->map);
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

void	deploy_message(int action)
{
	if (action == 1)
	{
		ft_printf(CYAN"===============================================================\n"RESET);
		ft_printf(GREEN" __    __                                              \n");
		ft_printf("/\\ \\  /\\ \\                              __             \n");
		ft_printf("\\ `\\`\\/'/ ___   __  __      __  __  __/\\_\\    ___     \n");
		ft_printf(" `\\ `\\ /' / __`\\/\\ \\/\\ \\    /\\ \\/\\ \\/\\ \\/\\ \\ /' _ `\\   \n");
		ft_printf("   `\\ \\ \\/\\ \\L\\ \\ \\ \\_\\ \\   \\ \\ \\_/ \\_/ \\ \\ \\/\\ \\/\\ \\  \n");
		ft_printf("     \\ \\_\\ \\____/\\ \\____/    \\ \\___x___/'\\ \\_\\ \\_\\ \\_\\ \n");
		ft_printf("      \\/_/\\/___/  \\/___/      \\/__//__/   \\/_/\\/_/\\/_/ \n"RESET);
		ft_printf(CYAN"===============================================================\n"RESET);
	}
	else if (action == 2)
	{
		ft_printf(CYAN"===============================================================\n"RESET);
		ft_printf(RED" __    __                   ___                              \n");
		ft_printf("/\\ \\  /\\ \\                 /\\_ \\                             \n");
		ft_printf("\\ `\\`\\/'/  ___   __  __    \\//\\ \\     ___     ____     __    \n");
		ft_printf(" `\\ `\\ /' / __`\\/\\ \\/\\ \\     \\ \\ \\   / __`\\  /',__\\  /'__`\\  \n");
		ft_printf("   `\\ \\ \\/\\ \\L\\ \\ \\ \\_\\ \\     \\_\\ \\_/\\ \\L\\ \\/\\__, `\\/\\  __/  \n");
		ft_printf("     \\ \\_\\ \\____/\\ \\____/     /\\____\\ \\____/\\/\\____/\\ \\____\\ \n");
		ft_printf("      \\/_/\\/___/  \\/___/      \\/____/\\/___/  \\/___/  \\/____/ \n"RESET);
		ft_printf(CYAN"===============================================================\n\n\n"RESET);

		ft_printf(RED"You were killed by an enemy\n"RESET);
	}
}

void	check_mv_enemy(t_data *data, char c)
{
	if (c == 'N')
	{
		data->n_mv += 1;
		ft_printf("Número de movimientos: %d\n",  data->n_mv);
		deploy_message(2);
		end_program(data);
	}
}

int	check_movement(t_data *data, int x, int y)
{
	char	c;
	c = ft_toupper(data->map[y][x]);
	check_mv_enemy(data, c);
	if (c == '1')
		return (0);
	if (c == 'C')
	{
		data->n_mv += 1;
		data->n_col -= 1;
		data->map[y][x] = '0';
		ft_printf("Número de movimientos: %d\n",  data->n_mv);
		return (1);
	}
	if (c == '0' || c == 'P')
	{
		data->n_mv += 1;
		ft_printf("Número de movimientos: %d\n",  data->n_mv);
		return (1);
	}
	if (c == 'E' && data->n_col == 0)
	{
		data->n_mv += 1;
		ft_printf("Número de movimientos: %d\n",  data->n_mv);
		deploy_message(1);
		end_program(data);
	}
	return (0);
}

int	key_events(int keycode, t_data *data)
{
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
