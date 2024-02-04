/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:44:14 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/04 13:08:04 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	animate(t_data *data)
{
	static int	frames;
	void		*aux;

	if (!data->img_data.player)
		return (1);
	if (frames == 2000)
	{
		put_background(data, data->map);
		put_img(data, data->img_data.player, data->cords_p.x,
			data->cords_p.y);
	}
	if (frames == 3500)
	{
		aux = data->img_data.enemies;
		data->img_data.enemies = data->img_data.enemies2;
		put_background(data, data->map);
		data->img_data.enemies = aux;
		put_img(data, data->img_data.player2, data->cords_p.x,
			data->cords_p.y);
	}
	if (frames == 4000)
		frames = 0;
	frames++;
	return (0);
}
