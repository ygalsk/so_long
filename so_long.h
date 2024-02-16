/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:15:34 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/15 20:31:58 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// include needed libs
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/include/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

// define map
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define FILL 'F'

// define textures
# define WALL_PNG "./textures/wall.png"
# define FLOOR_PNG "./textures/floor.png"
# define PLAYER_PNG "./textures/player.png"
# define COLLECTIBLE_PNG "./textures/collectible.png"
# define EXIT_PNG "./textures/exit.png"

// Game struct definition
typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	char			**f_map;
	char			*map_temp;
	int				width;
	int				height;
	int				player_posx;
	int				player_posy;
	int				player_pos_found;
	int				moves;
	int				collectible;
	int				ex_count;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*floor_texture;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*colle_texture;
	mlx_texture_t	*exit_texture;
	mlx_image_t		*wall_images;
	mlx_image_t		*floor_images;
	mlx_image_t		*player_images;
	mlx_image_t		*colle_images;
	mlx_image_t		*exit_images;
}					t_game;

void				error(char *str);
void				load_image(t_game *img);
void				image_to_win(int x, int y, char c, t_game *img);
int					render_img(t_game *img);
int					map_file_check(char *filename);
int					quit_game(t_game *game);
void				keyhooks(mlx_key_data_t keydata, void *param);
void				free_img(t_game *game);
void				free_map(t_game *game);
int					map_file_check(char *filename);
void				file_to_map(t_game *game, int fd);
void				save_map(char *file, t_game *game);
void				find_player_position(t_game *game);
void				move_y(t_game *game, char key);
void				move_x(t_game *game, char key);
void				find_c(t_game *game);
void				get_c(t_game *game);
void				load_player(t_game *game);
void				image_in_map(int x, int y, char c, t_game *img);
void				load_map(int x, int y, char c, t_game *img);
void				check_chars(t_game *game);
void				find_ex(t_game *game);
void				check_size_and_char(t_game *game);
void				free_f_map(t_game *game);
void				get_f_map(t_game *game);
int					symbols_present(t_game *game);
void				check_path(t_game *game);

#endif
