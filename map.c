/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:11:42 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/16 21:43:03 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include "so_long.h"

void	map_file_check(char *filename)
{
	char	*temp;

	temp = ft_strnstr(filename, ".ber", ft_strlen(filename));
	if (temp == NULL)
		error("WRONG FILETYPE!");
	else if (ft_strlen(temp) > 4)
		error("WRONG FILE TYPE!");
	else
		return ;
}

void	file_to_map(t_game *game, int fd)
{
	game->line = get_next_line(fd);
	if (!game->line)
		error("EMPTY MAP!");
	if (game->line[0] == '\n')
		error("ERROR NEWLINE AT START OF MAP!");
	while (game->line)
	{
		game->map_temp = ft_strjoin_gnl(game->map_temp, game->line);
		free(game->line);
		if (!game->map_temp)
			error("READING MAP INTO STRUCTURE FAILED!");
		game->height++;
		game->line = get_next_line(fd);
	}
}

void	save_map(char *file, t_game *game)
{
	int	fd;

	game->map_temp = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("READING FROM FD FAILED!");
	file_to_map(game, fd);
	close(fd);
	nl_in_map(game);
	game->map = ft_split(game->map_temp, '\n');
	if (!game->map)
	{
		free_map(game);
		error("SAVING MAP FAILED!");
	}
	game->width = ft_strlen(game->map[0]);
	free(game->map_temp);
}

void	nl_in_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_temp[i + 1])
	{
		if (game->map_temp[i] == '\n' && game->map_temp[i + 1] == '\n')
			error("EMPTY LINE IN MIDDLE OF MAP!");
		i++;
	}
}
