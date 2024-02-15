/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:22:36 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/15 19:41:04 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_chars(t_game *game)
{
	find_ex(game);
	find_player_position(game);
	if (game->collectible == 0)
		error("NO COLLECTIBLES!!!");
	if (game->ex_count != 1)
		error("NEED 1 EXIT!");
	if (game->player_pos_found != 1)
		error("NEED 1 PLAYER!");
	check_size_and_char(game);
}

void	check_size_and_char(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if ((game->map[0][x] != WALL) || (game->map[y][0] != WALL) ||
				(game->map[game->height - 1][x] != WALL) ||
				(game->map[y][game->width - 1] != WALL))
				error("MAP IS NOT SURROUNDED BY WALLS!");
			if (!(ft_strchr("01CPE", game->map[y][x])))
				error("ONLY USE 01CPE IN MAP_FILE!");
			x++;
		}
		y++;
	}
}

void	get_f_map(t_game *game)
{
	int	i;

	game->f_map = (char **)malloc(game->height * sizeof(char *));
	if (!game->f_map)
		error("MEMORY ALLOCATION FOR F_MAP FAILED!");
	i = 0;
	while (i < game->height)
	{
		game->f_map[i] = ft_strdup(game->map[i]);
		if (!game->f_map[i])
			error("MEMORY ALLOCATION FOR F_MAP FAILED!");
		i++;
	}
}

void	flood_fill(t_game *game, int y, int x)
{
	if ((game->f_map[y][x] == WALL) || (game->f_map[y][x] == FILL))
		return ;
	game->f_map[y][x] = FILL;
	flood_fill(game, y, x + 1);
	flood_fill(game, y, x - 1);
	flood_fill(game, y + 1, x);
	flood_fill(game, y - 1, x);
}

void	check_path(t_game *game)
{
	get_f_map(game);
	flood_fill(game, game->player_posy, game->player_posx);
	if (symbols_present(game))
		error("NO VALID PATH");
}
