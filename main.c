/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:52:27 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/29 17:55:15 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->width * PIXEL, game->height * PIXEL, "so_long", \
			true);
	if (!game->mlx)
		error("GAME INITIALIZATION FAILED!");
	load_image(game);
	render_img(game);
	mlx_image_to_window(game->mlx, game->player_images, game->player_posx \
			* PIXEL, game->player_posy * PIXEL);
	mlx_key_hook(game->mlx, keyhooks, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error("NEED 2 ARGUMENTS: PROGRAMM AND MAP!");
	map_file_check(argv[1]);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		error("MEMORY ALLOCATION FOR STRUCTURE FAILED");
	save_map(argv[1], game);
	check_chars(game);
	check_path(game);
	game_init(game);
	mlx_terminate(game->mlx);
	quit_game(game);
}
