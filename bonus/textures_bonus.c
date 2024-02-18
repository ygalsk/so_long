/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:04:58 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/18 20:45:50 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_image(t_game *game)
{
	game->exit_texture = mlx_load_png(EXIT_PNG);
	game->exit_images = mlx_texture_to_image(game->mlx, game->exit_texture);
	game->wall_texture = mlx_load_png(WALL_PNG);
	game->wall_images = mlx_texture_to_image(game->mlx, game->wall_texture);
	game->colle_texture = mlx_load_png(COLLECTIBLE_PNG);
	game->colle_images = mlx_texture_to_image(game->mlx, game->colle_texture);
	game->floor_texture = mlx_load_png(FLOOR_PNG);
	game->floor_images = mlx_texture_to_image(game->mlx, game->floor_texture);
	game->player_texture1 = mlx_load_png(PLAYER1_PNG);
	game->player_images1 = mlx_texture_to_image(game->mlx,
			game->player_texture1);
	game->player_texture2 = mlx_load_png(PLAYER2_PNG);
	game->player_images2 = mlx_texture_to_image(game->mlx,
			game->player_texture2);
	game->player_texture3 = mlx_load_png(PLAYER3_PNG);
	game->player_images3 = mlx_texture_to_image(game->mlx,
			game->player_texture3);
	game->player_texture4 = mlx_load_png(PLAYER4_PNG);
	game->player_images4 = mlx_texture_to_image(game->mlx,
			game->player_texture4);
}

void	image_in_map(int x, int y, char c, t_game *game)
{
	if (c == FLOOR || c == EXIT || c == COLLECTIBLE || c == PLAYER)
		mlx_image_to_window(game->mlx, game->floor_images, x * PIXEL, y * PIXEL);
	if (c == EXIT)
		mlx_image_to_window(game->mlx, game->exit_images, x * PIXEL, y * PIXEL);
	if (c == WALL)
		mlx_image_to_window(game->mlx, game->wall_images, x * PIXEL, y * PIXEL);
	if (c == COLLECTIBLE)
		mlx_image_to_window(game->mlx, game->colle_images, x * PIXEL, y * PIXEL);
}

int	render_img(t_game *game)
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
			}
			image_in_map(x, y, game->map[y][x], game);
			x++;
		}
		y++;
	}
	return (0);
}

void	load_player(t_game *game)
{
	game->player_images1 = mlx_texture_to_image(game->mlx, \
			game->player_texture1);
	// player->player_images2 = mlx_texture_to_image(game->mlx, \
	// 		player->player_texture2);
	// player->player_images3 = mlx_texture_to_image(game->mlx, \
	// 		player->player_texture3);
	// player->player_images4 = mlx_texture_to_image(game->mlx, \
	// 		player->player_texture4);
}

void	load_map(int x, int y, char c, t_game *game)
{
	if (c == FLOOR || c == EXIT || c == COLLECTIBLE || c == PLAYER)
		mlx_image_to_window(game->mlx, game->floor_images, x * PIXEL, y * PIXEL);
}
