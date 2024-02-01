/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:18 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/01 16:46:46 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	put_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->g_data.mlx, data->g_data.window, \
		img, x * PIXEL_SIZE, y * PIXEL_SIZE);
}