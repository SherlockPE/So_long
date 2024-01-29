/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:10:04 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/29 12:49:58 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef PIXEL_SIZE
#  define PIXEL_SIZE 64
# endif

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

//Structure
typedef struct so_long
{
	void	*mlx;
	void	*window;
}			grafic_init;

typedef struct images
{
	void	*player;
	void	*enemies;
	void	*colectibles;
	void	*walls;
	void	*floor;
}			img_game;

// Colours
# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;97m"
# define RESET "\033[0m"

//Background
# define B_RED "\033[0;41m"

//Utils
void		ft_perror(char *message);
char		**create_map(char *path);
void		free_map(char **map);
void		print_map(char **matrix);
char		**copy_map(char **map);

//Checkers
void		check_map(char **matrix);
void		check_extention(char *path);
void		check_valid_exit(char *path);

//Grafics
void		start_grafics(char **matrix, void **start, void **window);
void		create_images(img_game *img_ctent, grafic_init init);
// void		*create_images(void *mlx, char *path);
void		put_images(void *mlx, void *mlx_window, img_game img_data);

#endif