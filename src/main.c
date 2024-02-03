/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:15:36 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/03 14:15:17 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	detect_leaks(void)
{
	system("leaks so_long");
}

char	**checkers(char **argv)
{
	char	**map;
	
	map = create_map(argv[1]);
	check_map(map);
	check_valid_exit(argv[1]);
	ft_printf(GREEN "\nMAP IS OK ✅\n"RESET);
	return (map);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	//MAP											<------FIRST PART DONE
	if (argc <= 1)
		ft_perror("Arguments not valid");
	check_extention(argv[1]);

	data.map = checkers(argv);
	print_map(data.map);

	//GRAFICS
	deploy_playground(data.map, &data);

	//ANIMATIONS
	mlx_loop_hook(data.g_data.mlx, animate, &data);

	//MOVEMENTS
	data.n_mv = 0;
	count_collectibles(data.map, &data.n_col);
	mlx_hook(data.g_data.window, 2, (1L<<0), key_events, &data);
	mlx_loop(data.g_data.mlx);
	free_map(data.map);

}
