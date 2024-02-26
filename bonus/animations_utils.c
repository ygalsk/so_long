/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:36:02 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/26 18:36:21 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_w_util(t_game *game)
{
	if (game->moves % 2 == 0)
	{
		game->image->player_images4_1->instances->enabled = false;
		game->image->player_images4->instances->enabled = true;
		game->image->player = game->image->player_images4;
	}
	else if (game->moves % 2 != 0)
	{
		game->image->player_images4->instances->enabled = false;
		game->image->player_images4_1->instances->enabled = true;
		game->image->player = game->image->player_images4_1;
	}
}

void	player_s_util(t_game *game)
{
	if (game->moves % 2 == 0)
	{
		game->image->player_images1_2->instances->enabled = false;
		game->image->player_images1_1->instances->enabled = true;
		game->image->player = game->image->player_images1_1;
	}
	else if (game->moves % 2 != 0)
	{
		game->image->player_images1_1->instances->enabled = false;
		game->image->player_images1_2->instances->enabled = true;
		game->image->player = game->image->player_images1_2;
	}
}

void	player_a_util(t_game *game)
{
	if (game->moves % 2 == 0)
	{
		game->image->player_images3_1->instances->enabled = false;
		game->image->player_images3->instances->enabled = true;
		game->image->player = game->image->player_images3;
	}
	else if (game->moves % 2 != 0)
	{
		game->image->player_images3->instances->enabled = false;
		game->image->player_images3_1->instances->enabled = true;
		game->image->player = game->image->player_images3_1;
	}
}

void	player_d_util(t_game *game)
{
	if (game->moves % 2 == 0)
	{
		game->image->player_images2_1->instances->enabled = false;
		game->image->player_images2->instances->enabled = true;
		game->image->player = game->image->player_images2;
	}
	else if (game->moves % 2 != 0)
	{
		game->image->player_images2->instances->enabled = false;
		game->image->player_images2_1->instances->enabled = true;
		game->image->player = game->image->player_images2_1;
	}
}
