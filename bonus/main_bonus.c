/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:04:06 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/18 20:45:49 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_init(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->width * PIXEL, game->height * PIXEL, "so_long", true);
	if (!game->mlx)
		error("GAME INITIALIZATION FAILED!");
	load_image(game);
	render_img(game);
	mlx_image_to_window(game->mlx, game->player_images1, game->player_posx \
			* PIXEL, game->player_posy * PIXEL);
	mlx_image_to_window(game->mlx, game->player_images2, game->player_posx \
			* PIXEL, game->player_posy * PIXEL);
	game->player_images2->instances->enabled = false;
	mlx_image_to_window(game->mlx, game->player_images3, game->player_posx \
			* PIXEL, game->player_posy * PIXEL);
	game->player_images3->instances->enabled = false;
	mlx_image_to_window(game->mlx, game->player_images4, game->player_posx \
			* PIXEL, game->player_posy * PIXEL);
	game->player_images4->instances->enabled = true;
	mlx_key_hook(game->mlx, keyhooks, game);
	mlx_loop(game->mlx);
}

void	leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc != 2)
		error("NEED 2 ARGUMENTS: PROGRAMM AND MAP!");
	// atexit(&leaks);
	map_file_check(argv[1]);
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		error("MEMORY ALLOCATION FOR STRUCTURE FAILED");
	save_map(argv[1], game);
	find_c(game);
	check_chars(game);
	check_path(game);
	game_init(game);
	mlx_terminate(game->mlx);
	quit_game(game);
}
