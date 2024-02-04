/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:15:36 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/04 12:35:43 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/* void	detect_leaks(void)
{
	system("leaks so_long");
}
 */

char	**checkers(char **argv)
{
	char	**map;

	map = create_map(argv[1]);
	check_map(map);
	check_valid_exit(argv[1]);
	ft_printf(GREEN "\nMAP IS OK ✅\n" RESET);
	return (map);
}

void	deploy_playground(char **map, t_data *data)
{
	start_grafics(map, data);
	create_images(data);
	put_background(data, map);
	search_player(data, map);
	put_player(data);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc <= 1)
		ft_perror("Arguments not valid");
	check_extention(argv[1]);
	data.map = checkers(argv);
	print_map(data.map);
	deploy_playground(data.map, &data);
	mlx_loop_hook(data.g_data.mlx, animate, &data);
	data.n_mv = 0;
	count_collectibles(data.map, &data.n_col);
	mlx_hook(data.g_data.window, 2, (1L << 0), key_events, &data);
	mlx_loop(data.g_data.mlx);
	free_map(data.map);
}
