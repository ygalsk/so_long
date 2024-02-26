/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:43:55 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/26 18:44:27 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_player_image(t_game *game)
{
	game->texture->player_texture1 = mlx_load_png(PLAYER1_PNG);
	game->image->player_images1 = mlx_texture_to_image(game->mlx, \
										game->texture->player_texture1);
	game->texture->player_texture1_1 = mlx_load_png(PLAYER1_1_PNG);
	game->image->player_images1_1 = mlx_texture_to_image(game->mlx, \
										game->texture->player_texture1_1);
	game->texture->player_texture1_2 = mlx_load_png(PLAYER1_2_PNG);
	game->image->player_images1_2 = mlx_texture_to_image(game->mlx, \
										game->texture->player_texture1_2);
	game->texture->player_texture2 = mlx_load_png(PLAYER2_PNG);
	game->image->player_images2 = mlx_texture_to_image(game->mlx, \
										game->texture->player_texture2);
	game->texture->player_texture2_1 = mlx_load_png(PLAYER2_1_PNG);
	game->image->player_images2_1 = mlx_texture_to_image(game->mlx, \
										game->texture->player_texture2_1);
}

void	load_player_image_2(t_game *game)
{
	game->texture->player_texture3 = mlx_load_png(PLAYER3_PNG);
	game->image->player_images3 = mlx_texture_to_image(game->mlx, \
										game->texture->player_texture3);
	game->texture->player_texture3_1 = mlx_load_png(PLAYER3_1_PNG);
	game->image->player_images3_1 = mlx_texture_to_image(game->mlx, \
										game->texture->player_texture3_1);
	game->texture->player_texture4 = mlx_load_png(PLAYER4_PNG);
	game->image->player_images4 = mlx_texture_to_image(game->mlx, \
										game->texture->player_texture4);
	game->texture->player_texture4_1 = mlx_load_png(PLAYER4_1_PNG);
	game->image->player_images4_1 = mlx_texture_to_image(game->mlx, \
										game->texture->player_texture4_1);
}
