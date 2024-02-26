/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stuff_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:02:57 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/26 17:54:20 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_ex(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == EXIT)
				game->ex_count++;
			x++;
		}
		y++;
	}
}

int	symbols_present(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->f_map[y][x] == COLLECTIBLE || game->f_map[y][x] == EXIT)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	find_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == PLAYER)
			{
				game->player->player_posx = x;
				game->player->player_posy = y;
				game->player->player_pos_found++;
			}
			x++;
		}
		y++;
	}
}

void	find_c(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == COLLECTIBLE)
				game->collectible++;
			x++;
		}
		y++;
	}
}

void	get_c(t_game *game)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	x = game->player->player_posx;
	y = game->player->player_posy;
	if (game->map[y][x] == COLLECTIBLE)
	{
		while (i < game->collectible)
		{
			if (game->image->colle_images->instances[i].x == x * PIXEL
				&& game->image->colle_images->instances[i].y == y * PIXEL)
			{
				game->map[y][x] = FLOOR;
				game->image->colle_images->instances[i].enabled = false;
				game->left_collectible--;
				break ;
			}
			i++;
		}
		ft_printf("Collectibles left: %d\n", game->left_collectible);
	}
	chech_exit(game);
}
