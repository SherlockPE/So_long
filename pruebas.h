/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:09:14 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/01 14:13:46 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRUEBAS_H
# define PRUEBAS_H

# ifndef PIXEL_SIZE
#  define PIXEL_SIZE 64
# endif

//ESQ
# ifndef ESC
#  define ESC 53
# endif

//WASD
# ifndef UP_L
#  define UP_L 13
# endif

# ifndef LEFT_L
#  define LEFT_L 0
# endif

# ifndef DOWN_L
#  define DOWN_L 1
# endif

# ifndef RIGHT_L
#  define RIGHT_L 2
# endif

//ARROWS
# ifndef UP_D
#  define UP_D 126
# endif

# ifndef LEFT_D
#  define LEFT_D 123
# endif

# ifndef DOWN_D
#  define DOWN_D 125
# endif

# ifndef RIGHT_D
#  define RIGHT_D 124
# endif

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;

	void	*player;
	void	*walls;
	void	*floor;


	int		x_cords;
	int		y_cords;
}			t_data;



#endif