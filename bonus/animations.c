/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:59:13 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/29 15:31:30 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_w(t_game *game)
{
	if (game->map[game->player->player_posy \
		- 1][game->player->player_posx] == WALL)
		return ;
	game->player->player_posy -= 1;
	player_w_util(game);
	game->moves++;
	game->image->player->instances[0].y = game->player->player_posy * PIXEL;
	game->image->player->instances[0].x = game->player->player_posx * PIXEL;
	game->image->player_images1->instances->enabled = false;
	game->image->player_images1_1->instances->enabled = false;
	game->image->player_images1_2->instances->enabled = false;
	game->image->player_images2->instances->enabled = false;
	game->image->player_images2_1->instances->enabled = false;
	game->image->player_images3->instances->enabled = false;
	game->image->player_images3_1->instances->enabled = false;
}

void	player_s(t_game *game)
{
	if (game->map[game->player->player_posy \
		+ 1][game->player->player_posx] == WALL)
		return ;
	game->player->player_posy += 1;
	player_s_util(game);
	game->moves++;
	game->image->player->instances[0].y = game->player->player_posy * PIXEL;
	game->image->player->instances[0].x = game->player->player_posx * PIXEL;
	game->image->player_images2->instances->enabled = false;
	game->image->player_images2_1->instances->enabled = false;
	game->image->player_images3->instances->enabled = false;
	game->image->player_images3_1->instances->enabled = false;
	game->image->player_images4->instances->enabled = false;
	game->image->player_images4_1->instances->enabled = false;
}

void	player_a(t_game *game)
{
	if (game->map[game->player->player_posy][game->player->player_posx
		- 1] == WALL)
		return ;
	game->player->player_posx -= 1;
	player_a_util(game);
	game->moves++;
	game->image->player->instances[0].y = game->player->player_posy * PIXEL;
	game->image->player->instances[0].x = game->player->player_posx * PIXEL;
	game->image->player_images2->instances->enabled = false;
	game->image->player_images2_1->instances->enabled = false;
	game->image->player_images1->instances->enabled = false;
	game->image->player_images1_1->instances->enabled = false;
	game->image->player_images1_2->instances->enabled = false;
	game->image->player_images4->instances->enabled = false;
	game->image->player_images4_1->instances->enabled = false;
}

void	player_d(t_game *game)
{
	if (game->map[game->player->player_posy][game->player->player_posx
		+ 1] == WALL)
		return ;
	game->player->player_posx += 1;
	player_d_util(game);
	game->moves++;
	game->image->player->instances[0].y = game->player->player_posy * PIXEL;
	game->image->player->instances[0].x = game->player->player_posx * PIXEL;
	game->image->player_images1->instances->enabled = false;
	game->image->player_images1_1->instances->enabled = false;
	game->image->player_images1_2->instances->enabled = false;
	game->image->player_images3->instances->enabled = false;
	game->image->player_images3_1->instances->enabled = false;
	game->image->player_images4->instances->enabled = false;
	game->image->player_images4_1->instances->enabled = false;
}
