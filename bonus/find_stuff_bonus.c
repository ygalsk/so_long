/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stuff_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:02:57 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/17 22:27:26 by dkremer          ###   ########.fr       */
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
	int		y;
	int		x;

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
				game->player_posx = x;
				game->player_posy = y;
				game->player_pos_found++;
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

	x = game->player_posx;
	y = game->player_posy;
	if (game->map[y][x] == COLLECTIBLE)
	{
		game->collectible--;
		game->map[y][x] = FLOOR;
		ft_printf("Collectibles left: %d\n", game->collectible);
		load_player(game);
		load_map(x, y, game->map[y][x], game);
		game->player_posx = x;
		game->player_posy = y;
		mlx_image_to_window(game->mlx, game->player_images, game->player_posx \
											* 64, game->player_posy * 64);
		get_to_exit(game);
	}
	if (game->map[y][x] == EXIT)
	{
		if (game->collectible != 0)
			return ;
		ft_printf("CONGRATS!%s");
		quit_game(game);
	}
}
