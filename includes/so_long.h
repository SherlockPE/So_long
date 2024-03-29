/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:10:04 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/04 13:07:35 by flopez-r         ###   ########.fr       */
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
	void			*player2;
	void			*enemies;
	void			*enemies2;
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
	t_cords			cords_p;
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
void				print_mc(char actual);
char				**copy_map(char **map);
void				deploy_message(int action, t_data *data);
void				end_program(t_data *data, int exit_code);

//Checkers
void				check_map(char **matrix);
void				check_extention(char *path);
void				check_valid_exit(char *path);

//Start Grafics
void				start_grafics(char **matrix, t_data *data);
void				create_images(t_data *data);
void				search_player(t_data *data, char **map);
void				put_information(t_data *data, int y);
void				put_background(t_data *data, char **map);

//Grafic utils
void				put_img(t_data *data, void *img, int x, int y);
void				put_player(t_data *data);
void				reset_player(t_data *data, char **map);
void				error_create_img(t_data *data);
void				put_mc_to_win(t_data *data, char c, int x, int y);

//Events
int					key_events(int keycode, t_data *data);

//Animations
int					animate(t_data *data);
#endif