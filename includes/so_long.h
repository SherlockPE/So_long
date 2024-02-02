/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:10:04 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/02 15:30:35 by flopez-r         ###   ########.fr       */
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

//Structure
typedef struct s_grafic_init
{
	void			*mlx;
	void			*window;
}					t_grafic_init;

typedef struct s_img_game
{
	void			*player;
	void			*enemies;
	void			*end;
	void			*colectibles;
	void			*walls;
	void			*floor;
}					t_img_game;

typedef struct s_cords
{
	int				x;
	int				y;
}					t_cords;

typedef struct s_data
{
	t_grafic_init	g_data;
	t_img_game		img_data;
	t_cords			cords_player;
	char			**map;

	int				n_mv;
	int				n_col;
}					t_data;

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

//Map
void				count_collectibles(char **map, int *col);

//Utils
void				ft_perror(char *message);
char				**create_map(char *path);
void				free_map(char **map);
void				print_map(char **matrix);
char				**copy_map(char **map);

//Checkers
void				check_map(char **matrix);
void				check_extention(char *path);
void				check_valid_exit(char *path);

//Grafics
void				deploy_playground(char **map, t_data *data);
void				put_background(t_data *data, char **map);
void				put_img(t_data *data, void *img, int x, int y);
int					key_events(int keycode, t_data *data);
void				deploy_message(int action);
void				end_program(t_data *data);

#endif