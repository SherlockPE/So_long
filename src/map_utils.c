/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:13:19 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/04 12:22:56 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	get_alto(char *path)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

//A funçao lê um arquivo e retorna uma matriz no mapa
char	**create_map(char *path)
{
	char	**matrix;
	int		alto;
	int		i;
	int		fd;

	alto = get_alto(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_perror("No se pudo abrir el archivo");
	matrix = (char **)ft_calloc(alto + 1, sizeof(char *));
	if (!matrix)
		ft_perror("Malloc error\n");
	i = 0;
	while (1)
	{
		matrix[i] = get_next_line(fd);
		if (matrix[i] == 0)
			break ;
		i++;
	}
	close(fd);
	return (matrix);
}

//Function Checks if the extention of the archive is .ber
void	check_extention(char *path)
{
	int		i;
	int		len;
	char	*extention;

	len = ft_strlen(path);
	len -= 4;
	extention = ft_calloc(5, 1);
	if (!extention)
		ft_perror("Malloc error 🥁");
	i = 0;
	while (i < len && path[len])
	{
		extention[i] = path[len];
		i++;
		len++;
	}
	if (ft_strncmp(extention, ".ber", ft_strlen(path)) != 0)
	{
		free(extention);
		extention = NULL;
		ft_perror("This extention is no valid for this proyect 😪");
	}
	free(extention);
	extention = NULL;
}

//Function print the main characters
void	print_mc(char actual)
{
	if (actual == '1')
		ft_printf(CYAN "%c" RESET, actual);
	else if (actual == '0')
		ft_printf("%c", actual);
	else if (actual == 'P')
		ft_printf(BLUE "%c" RESET, actual);
	else if (actual == 'C')
		ft_printf(YELLOW "%c" RESET, actual);
	else if (actual == 'E')
		ft_printf(YELLOW "%c" RESET, actual);
	else
		ft_printf(RED"%c"RESET, actual);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	map = NULL;
}
