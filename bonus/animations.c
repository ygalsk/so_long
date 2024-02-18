/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:59:13 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/18 20:45:49 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_w(t_game *game)
{
	if (game->map[game->player_posy - 1][game->player_posx] == WALL)
		return ;
	game->player_posy -= 1;
	game->moves++;
	game->player_images4->instances->enabled = true;
	game->player_images4->instances[0].y = game->player_posy * PIXEL;
	game->player_images4->instances[0].x = game->player_posx * PIXEL;
	game->player_images1->instances->enabled = false;
	game->player_images2->instances->enabled = false;
	game->player_images3->instances->enabled = false;
}

void	player_s(t_game *game)
{
	if (game->map[game->player_posy + 1][game->player_posx] == WALL)
		return ;
	game->player_posy += 1;
	game->moves++;
	game->player_images1->instances->enabled = true;
	game->player_images1->instances[0].y = game->player_posy * PIXEL;
	game->player_images1->instances[0].x = game->player_posx * PIXEL;
	game->player_images2->instances->enabled = false;
	game->player_images3->instances->enabled = false;
	game->player_images4->instances->enabled = false;
}

void	player_a(t_game *game)
{
	if (game->map[game->player_posy][game->player_posx - 1] == WALL)
		return ;
	game->player_posx -= 1;
	game->moves++;
	game->player_images3->instances->enabled = true;
	game->player_images3->instances[0].y = game->player_posy * PIXEL;
	game->player_images3->instances[0].x = game->player_posx * PIXEL;
	game->player_images2->instances->enabled = false;
	game->player_images1->instances->enabled = false;
	game->player_images4->instances->enabled = false;
}

void	player_d(t_game *game)
{
	if (game->map[game->player_posy][game->player_posx + 1] == WALL)
		return ;
	game->player_posx += 1;
	game->moves++;
	game->player_images2->instances->enabled = true;
	game->player_images2->instances[0].y = game->player_posy * PIXEL;
	game->player_images2->instances[0].x = game->player_posx * PIXEL;
	game->player_images1->instances->enabled = false;
	game->player_images3->instances->enabled = false;
	game->player_images4->instances->enabled = false;
}
