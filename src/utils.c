/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:44:22 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/04 13:19:09 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_perror(char *message)
{
	ft_printf(RED "Error ❌\n" RESET);
	ft_printf(RED "%s\n" RESET, message);
	exit(EXIT_FAILURE);
}

//Function prints an array of arrays (the map)
void	print_map(char **matrix)
{
	int		i;
	int		j;
	char	actual;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			actual = ft_toupper(matrix[i][j]);
			print_mc(actual);
			j++;
		}
		i++;
	}
	ft_printf("\n");
}

void	deploy_message(int action, t_data *data)
{
	if (action == 1)
	{
		ft_printf(CYAN "=====================================\n" RESET);
		ft_printf(GREEN " __   __                     _        \n");
		ft_printf(" \\ \\ / /__  _   _  __      _(_)_ __   \n");
		ft_printf("  \\ V / _ \\| | | | \\ \\ /\\ / / | '_ \\  \n");
		ft_printf("   | | (_) | |_| |  \\ V  V /| | | | | \n");
		ft_printf("   |_|\\___/ \\__,_|   \\_/\\_/ |_|_| |_| \n" RESET);
		ft_printf(CYAN "=====================================\n\n"RESET);
		ft_printf(GREEN"Number of movements: %d\n" RESET, data->n_mv);
	}
	else if (action == 2)
	{
		ft_printf(CYAN "=====================================\n" RESET);
		ft_printf(RED"__   __            _                 \n");
		ft_printf("\\ \\ / /           | |                \n");
		ft_printf(" \\ V /___  _   _  | | ___  ___  ___  \n");
		ft_printf("  \\ // _ \\| | | | | |/ _ \\/ __|/ _ \\ \n");
		ft_printf("  | | (_) | |_| | | | (_) \\__ \\  __/ \n");
		ft_printf("  \\_/\\___/ \\__,_| |_|\\___/|___/\\___| \n");
		ft_printf("                                     \n"RESET);
		ft_printf(CYAN "=====================================\n\n" RESET);
		ft_printf(RED "You were killed by a tramp\n");
		ft_printf("Number of movements: %d\n" RESET, data->n_mv);
	}
}

void	end_program(t_data *data, int exit_code)
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
	exit(exit_code);
}
