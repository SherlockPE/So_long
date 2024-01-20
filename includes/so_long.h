/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:10:04 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/20 15:14:11 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>

// Colours
# define RED	 "\033[0;31m"
# define BLUE	"\033[0;34m"
# define GREEN	 "\033[0;32m"
# define CYAN	"\033[0;36m"
# define WHITE	"\033[0;97m"
# define RESET	"\033[0m"

//Background
# define B_RED	 "\033[0;41m"


//Utils
void	ft_perror(char *message);
char	**create_map(char *path);
void	free_map(char **map);

//Checkers
void	check_map(char **matrix);
void	check_extention(char *path);

#endif