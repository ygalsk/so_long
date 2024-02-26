/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:49:15 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/26 19:51:46 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	delete_player_texture(t_game *game)
{
	mlx_delete_texture(game->texture->player_texture1);
	mlx_delete_texture(game->texture->player_texture1_1);
	mlx_delete_texture(game->texture->player_texture1_2);
	mlx_delete_texture(game->texture->player_texture2);
	mlx_delete_texture(game->texture->player_texture2_1);
	mlx_delete_texture(game->texture->player_texture3);
	mlx_delete_texture(game->texture->player_texture3_1);
	mlx_delete_texture(game->texture->player_texture4);
	mlx_delete_texture(game->texture->player_texture4_1);
}

void	delete_player_image(t_game *game)
{
	mlx_delete_image(game->mlx, game->image->player_images1);
	mlx_delete_image(game->mlx, game->image->player_images1_1);
	mlx_delete_image(game->mlx, game->image->player_images1_2);
	mlx_delete_image(game->mlx, game->image->player_images2);
	mlx_delete_image(game->mlx, game->image->player_images2_1);
	mlx_delete_image(game->mlx, game->image->player_images3);
	mlx_delete_image(game->mlx, game->image->player_images3_1);
	mlx_delete_image(game->mlx, game->image->player_images4);
	mlx_delete_image(game->mlx, game->image->player_images4_1);
}
