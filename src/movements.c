/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:19:19 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/04 13:13:02 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	check_mv_enemy(t_data *data, char c)
{
	if (c == 'N')
	{
		data->n_mv += 1;
		ft_printf("Número de movimientos: %d\n", data->n_mv);
		deploy_message(2, data);
		end_program(data, EXIT_SUCCESS);
	}
}

void	check_mv_exit(t_data *data, char c)
{
	if (c == 'E' && data->n_col == 0)
	{
		data->n_mv += 1;
		ft_printf("Número de movimientos: %d\n", data->n_mv);
		deploy_message(1, data);
		end_program(data, EXIT_SUCCESS);
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
		ft_printf("Número de movimientos: %d\n", data->n_mv);
		return (1);
	}
	if (c == '0' || c == 'P')
	{
		data->n_mv += 1;
		ft_printf("Número de movimientos: %d\n", data->n_mv);
		return (1);
	}
	check_mv_exit(data, c);
	return (0);
}

//Events of keyboard
int	key_events(int keycode, t_data *data)
{
	if (keycode == UP_L || keycode == UP_D)
	{
		if (check_movement(data, data->cords_p.x, data->cords_p.y - 1))
			data->cords_p.y -= 1;
	}
	else if (keycode == LEFT_L || keycode == LEFT_D)
	{
		if (check_movement(data, data->cords_p.x - 1, data->cords_p.y))
			data->cords_p.x -= 1;
	}
	else if (keycode == DOWN_L || keycode == DOWN_D)
	{
		if (check_movement(data, data->cords_p.x, data->cords_p.y + 1))
			data->cords_p.y += 1;
	}
	else if (keycode == RIGHT_L || keycode == RIGHT_D)
	{
		if (check_movement(data, data->cords_p.x + 1, data->cords_p.y))
			data->cords_p.x += 1;
	}
	else if (keycode == ESC)
		end_program(data, EXIT_SUCCESS);
	reset_player(data, data->map);
	return (1);
}
