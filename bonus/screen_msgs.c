/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_msgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:40:52 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/18 19:04:04 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_on_screen(t_game *game)
{
	char	*moves;
	char	*collects;
	char	*msg;
	char	*temp_moves;
	char	*temp_coll;

	temp_coll = ft_itoa(game->collectible);
	temp_moves = ft_itoa(game->moves);
	moves = ft_strjoin("MOVES: ", temp_moves);
	collects = ft_strjoin("COLLECTIBLES: ", temp_coll);
	msg = ft_strdup("MOVE TO EXIT NOW!");
	if (msg)
		mlx_delete_image(game->mlx, game->screen_msg);
	if (moves)
		mlx_delete_image(game->mlx, game->screen_moves);
	if (collects)
		mlx_delete_image(game->mlx, game->screen_collectibles);
	game->screen_moves = mlx_put_string(game->mlx, moves, 0, 0);
	game->screen_collectibles = mlx_put_string(game->mlx, collects, 0, 20);
	if (game->collectible == 0)
		game->screen_msg = mlx_put_string(game->mlx, msg, 10, 50);
	free_screen_msg(moves, collects, temp_coll, temp_moves);
	free(msg);
}

void	free_screen_msg(char *moves, char *coll, char *tempc, char *tempm)
{
	free(moves);
	free(coll);
	free(tempc);
	free(tempm);
}
