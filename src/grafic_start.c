/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/23 17:09:11 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void    start_grafics(char **matrix)
{
	void	*start;
	void	*img;
	void	*window;

	(void)matrix;
	//Inicialize the window;
	
	start = mlx_init();
	window = mlx_new_window(start, 100, 100, "So_long");
	img = mlx_new_image(start, 50, 50);
	
}