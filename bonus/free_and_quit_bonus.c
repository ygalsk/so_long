/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_quit_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:03:36 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/26 19:52:39 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_img(t_game *game)
{
	mlx_delete_texture(game->texture->exit_texture);
	mlx_delete_texture(game->texture->wall_texture);
	mlx_delete_texture(game->texture->colle_texture);
	mlx_delete_texture(game->texture->floor_texture);
	mlx_delete_image(game->mlx, game->image->player);
	mlx_delete_image(game->mlx, game->image->exit_images);
	mlx_delete_image(game->mlx, game->image->wall_images);
	mlx_delete_image(game->mlx, game->image->colle_images);
	mlx_delete_image(game->mlx, game->image->floor_images);
	mlx_delete_image(game->mlx, game->image->screen_moves);
	mlx_delete_image(game->mlx, game->image->screen_collectibles);
	mlx_delete_image(game->mlx, game->image->screen_msg);
	mlx_close_window(game->mlx);
	delete_player_texture(game);
	delete_player_image(game);
	free_map(game);
	free_f_map(game);
}

void	free_f_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->f_map[i]);
		i++;
	}
	free(game->f_map);
}

int	quit_game(t_game *game)
{
	free_img(game);
	free(game->player);
	free(game->texture);
	free(game->image);
	free(game);
	exit(EXIT_SUCCESS);
}

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}
