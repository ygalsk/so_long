/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:04:06 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/26 17:17:21 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdlib.h>

void	game_init(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->width * PIXEL, game->height * PIXEL, "so_long",
			true);
	if (!game->mlx)
		error("GAME INITIALIZATION FAILED!");
	load_image(game);
	render_img(game);
	load_player(game);
	mlx_key_hook(game->mlx, keyhooks, game);
	mlx_loop(game->mlx);
}

void	alloc_struct(t_game *game)
{
	game->image = ft_calloc(1, sizeof(t_image));
	game->texture = ft_calloc(1, sizeof(t_texture));
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->image || !game->texture || !game->player)
		error("MEMORY ALLOCATION FOR STRUCTURE FAILED");
}

void	leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error("NEED 2 ARGUMENTS: PROGRAMM AND MAP!");
	atexit(&leaks);
	map_file_check(argv[1]);
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		error("MEMORY ALLOCATION FOR STRUCTURE FAILED");
	alloc_struct(game);
	save_map(argv[1], game);
	check_chars(game);
	game->left_collectible = game->collectible;
	check_path(game);
	game_init(game);
	mlx_terminate(game->mlx);
	quit_game(game);
}
