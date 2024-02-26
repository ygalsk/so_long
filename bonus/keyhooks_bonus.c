/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:57:32 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/26 19:54:16 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	put_on_screen(game);
	return ;
}

void	move_y(t_game *game, char key)
{
	if (key == W)
		player_w(game);
	if (key == S)
		player_s(game);
	ft_printf("Moves: %d\n", game->moves);
	get_c(game);
}

void	move_x(t_game *game, char key)
{
	if (key == A)
		player_a(game);
	if (key == D)
		player_d(game);
	ft_printf("Moves: %d\n", game->moves);
	get_c(game);
}

void	chech_exit(t_game *game)
{
	if (game->map[game->player->player_posy][game->player->player_posx] == EXIT \
		&& game->left_collectible == 0)
	{
		if (game->left_collectible != 0)
			return ;
		ft_printf("CONGRATS!%s");
		quit_game(game);
	}
}

void	get_to_exit(t_game *game)
{
	if (game->left_collectible == 0)
		ft_printf("HEAD TO EXIT NOW!\n");
}
