/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:04:58 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/26 18:44:11 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_image(t_game *game)
{
	game->texture->exit_texture = mlx_load_png(EXIT_PNG);
	game->image->exit_images = mlx_texture_to_image(game->mlx, \
										game->texture->exit_texture);
	game->texture->wall_texture = mlx_load_png(WALL_PNG);
	game->image->wall_images = mlx_texture_to_image(game->mlx, \
										game->texture->wall_texture);
	game->texture->colle_texture = mlx_load_png(COLLECTIBLE_PNG);
	game->image->colle_images = mlx_texture_to_image(game->mlx, \
										game->texture->colle_texture);
	game->texture->floor_texture = mlx_load_png(FLOOR_PNG);
	game->image->floor_images = mlx_texture_to_image(game->mlx, \
										game->texture->floor_texture);
	load_player_image(game);
	load_player_image_2(game);
}

void	image_in_map(int x, int y, char c, t_game *game)
{
	if (c == FLOOR || c == EXIT || c == COLLECTIBLE || c == PLAYER || c == WALL)
		mlx_image_to_window(game->mlx, game->image->floor_images, x * PIXEL, y \
				* PIXEL);
	if (c == EXIT)
		mlx_image_to_window(game->mlx, game->image->exit_images, x * PIXEL, y \
				* PIXEL);
	if (c == WALL)
		mlx_image_to_window(game->mlx, game->image->wall_images, x * PIXEL, y \
				* PIXEL);
	if (c == COLLECTIBLE)
		mlx_image_to_window(game->mlx, game->image->colle_images, x * PIXEL, y \
				* PIXEL);
}

void	render_img(t_game *game)
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
			}
			image_in_map(x, y, game->map[y][x], game);
			x++;
		}
		y++;
	}
}

void	load_player(t_game *game)
{
	game->image->player = game->image->player_images1;
	mlx_image_to_window(game->mlx, game->image->player, \
			game->player->player_posx * PIXEL, game->player->player_posy \
			* PIXEL);
	mlx_image_to_window(game->mlx, game->image->player_images1_1, \
			game->player->player_posx * PIXEL, game->player->player_posy \
			* PIXEL);
	game->image->player_images1_1->instances->enabled = false;
	mlx_image_to_window(game->mlx, game->image->player_images1_2, \
			game->player->player_posx * PIXEL, game->player->player_posy \
			* PIXEL);
	game->image->player_images1_2->instances->enabled = false;
	mlx_image_to_window(game->mlx, game->image->player_images2, \
			game->player->player_posx * PIXEL, game->player->player_posy \
			* PIXEL);
	game->image->player_images2->instances->enabled = false;
	mlx_image_to_window(game->mlx, game->image->player_images2_1, \
			game->player->player_posx * PIXEL, game->player->player_posy \
			* PIXEL);
	load_player_2(game);
}

void	load_player_2(t_game *game)
{
	game->image->player_images2_1->instances->enabled = false;
	mlx_image_to_window(game->mlx, game->image->player_images3, \
			game->player->player_posx * PIXEL, game->player->player_posy \
			* PIXEL);
	game->image->player_images3->instances->enabled = false;
	mlx_image_to_window(game->mlx, game->image->player_images3_1, \
			game->player->player_posx * PIXEL, game->player->player_posy \
			* PIXEL);
	game->image->player_images3_1->instances->enabled = false;
	mlx_image_to_window(game->mlx, game->image->player_images4, \
			game->player->player_posx * PIXEL, game->player->player_posy \
			* PIXEL);
	game->image->player_images4->instances->enabled = false;
	mlx_image_to_window(game->mlx, game->image->player_images4_1, \
			game->player->player_posx * PIXEL, game->player->player_posy \
			* PIXEL);
	game->image->player_images4_1->instances->enabled = false;
}
