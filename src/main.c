/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:15:36 by flopez-r          #+#    #+#             */
/*   Updated: 2024/01/17 18:22:14 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	ft_perror(char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

int	get_alto(int fd)
{
	int	i;
	char	*line;
	
	i = 0;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	return (i - 1);
}

char	**create_map(int fd)
{
	char	*line;
	char	**matrix;
	int		ancho;
	int		alto;


	matrix = 0;
	//Obtener el alto
	alto = get_alto(fd);

	//Obtener el ancho del mapa
	ancho = 0;
	line = get_next_line(fd);
	while (line[ancho])
		ancho++;
	
	ft_printf("Ancho: %d - Alto: %d", ancho, alto);
	return (matrix);
}

void	check_map(char *map)
{
	// char	**matrix;
	int		fd;

	fd = open(map, O_RDONLY);
	// matrix = create_map(fd);
	ft_printf("La altura es: %d\n", get_alto(fd));

}

int	main(int argc, char *argv[])
{
	if (argc <= 1)
		ft_perror("Arguments not valid");


	check_map(argv[1]);
	return (0);
}
