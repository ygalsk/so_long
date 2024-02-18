/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:40:50 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/17 22:37:24 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	keyhooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		quit_game(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) || \
		mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move_y(game, W);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S) || \
		mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move_y(game, S);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) || \
		mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		move_x(game, A);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D) || \
		mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		move_x(game, D);
	return ;
}

void	move_y(t_game *game, char key)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	if (key == W)
	{
		if (game->map[y - 1][x] == WALL)
			return ;
		game->player_posy -= 1;
		game->moves++;
		game->player_images->instances[0].y = game->player_posy * 64;
		game->player_images->instances[0].x = game->player_posx * 64;
	}
	if (key == S)
	{
		if (game->map[y + 1][x] == WALL)
			return ;
		game->player_posy += 1;
		game->moves++;
		game->player_images->instances[0].y = game->player_posy * 64;
		game->player_images->instances[0].x = game->player_posx * 64;
	}
	ft_printf("Moves: %d\n", game->moves);
	get_c(game);
}

void	move_x(t_game *game, char key)
{
	int	x;
	int	y;

	x = game->player_posx;
	y = game->player_posy;
	if (key == A)
	{
		if (game->map[y][x - 1] == WALL)
			return ;
		game->player_posx -= 1;
		game->moves++;
		game->player_images->instances[0].y = game->player_posy * 64;
		game->player_images->instances[0].x = game->player_posx * 64;
	}
	if (key == D)
	{
		if (game->map[y][x + 1] == WALL)
			return ;
		game->player_posx += 1;
		game->moves++;
		game->player_images->instances[0].y = game->player_posy * 64;
		game->player_images->instances[0].x = game->player_posx * 64;
	}
	ft_printf("Moves: %d\n", game->moves);
	get_c(game);
}

void	get_to_exit(t_game *game)
{
	if (game->collectible == 0)
		ft_printf("HEAD TO EXIT NOW!\n");
}
