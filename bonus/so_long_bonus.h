/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:06:47 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/29 16:10:19 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// include needed libs
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include <fcntl.h>

// define map and Keys
typedef enum e_elements
{
	WALL = '1',
	FLOOR = '0',
	PLAYER = 'P',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	FILL = 'F',
	PIXEL = 64,
	W = 'W',
	S = 'S',
	A = 'A',
	D = 'D',
}					t_elements;

// define textures
# define WALL_PNG "./textures/wall.png"
# define FLOOR_PNG "./textures/floor.png"
# define COLLECTIBLE_PNG "./textures/collectible.png"
# define EXIT_PNG "./textures/exit.png"
# define PLAYER1_PNG "./textures/player.png"
# define PLAYER1_1_PNG "./textures/player_1.png"
# define PLAYER1_2_PNG "./textures/player_2.png"
# define PLAYER2_PNG "./textures/player2.png"
# define PLAYER2_1_PNG "./textures/player2_1.png"
# define PLAYER3_PNG "./textures/player3.png"
# define PLAYER3_1_PNG "./textures/player3_1.png"
# define PLAYER4_PNG "./textures/player4.png"
# define PLAYER4_1_PNG "./textures/player4_1.png"

/* Game struct definition */

typedef struct s_texture
{
	mlx_texture_t	*player_texture1;
	mlx_texture_t	*player_texture1_1;
	mlx_texture_t	*player_texture1_2;
	mlx_texture_t	*player_texture2;
	mlx_texture_t	*player_texture2_1;
	mlx_texture_t	*player_texture3;
	mlx_texture_t	*player_texture3_1;
	mlx_texture_t	*player_texture4;
	mlx_texture_t	*player_texture4_1;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*floor_texture;
	mlx_texture_t	*colle_texture;
	mlx_texture_t	*exit_texture;
}					t_texture;

typedef struct s_image
{
	mlx_image_t		*wall_images;
	mlx_image_t		*floor_images;
	mlx_image_t		*colle_images;
	mlx_image_t		*exit_images;
	mlx_image_t		*screen_moves;
	mlx_image_t		*screen_collectibles;
	mlx_image_t		*screen_msg;
	mlx_image_t		*player;
	mlx_image_t		*player_images1;
	mlx_image_t		*player_images1_1;
	mlx_image_t		*player_images1_2;
	mlx_image_t		*player_images2;
	mlx_image_t		*player_images2_1;
	mlx_image_t		*player_images3;
	mlx_image_t		*player_images3_1;
	mlx_image_t		*player_images4;
	mlx_image_t		*player_images4_1;
}					t_image;

typedef struct s_player
{
	int				player_posx;
	int				player_posy;
	int				player_pos_found;
}					t_player;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	char			**f_map;
	char			*map_temp;
	int				width;
	int				height;
	int				moves;
	int				collectible;
	int				left_collectible;
	int				ex_count;
	char			*line;
	t_player		*player;
	t_texture		*texture;
	t_image			*image;
}					t_game;

void				error(char *str);
void				load_image(t_game *img);
void				load_player_image(t_game *game);
void				load_player_image_2(t_game *game);
void				render_img(t_game *img);
void				map_file_check(char *filename);
int					quit_game(t_game *game);
void				keyhooks(mlx_key_data_t keydata, void *param);
void				free_img(t_game *game);
void				free_map(t_game *game);
void				file_to_map(t_game *game, int fd);
void				save_map(char *file, t_game *game);
void				find_player_position(t_game *game);
void				move_y(t_game *game, char key);
void				move_x(t_game *game, char key);
void				find_c(t_game *game);
void				get_c(t_game *game);
void				image_in_map(int x, int y, char c, t_game *game);
void				check_chars(t_game *game);
void				find_ex(t_game *game);
void				check_size_and_char(t_game *game);
void				free_f_map(t_game *game);
void				get_f_map(t_game *game);
int					symbols_present(t_game *game);
void				check_path(t_game *game);
void				nl_in_map(t_game *game);
void				get_to_exit(t_game *game);
void				put_on_screen(t_game *game);
void				free_screen_msg(char *moves, char *coll, char *tempc,
						char *tempm);
void				player_w(t_game *game);
void				player_w_util(t_game *game);
void				player_s(t_game *game);
void				player_s_util(t_game *game);
void				player_a(t_game *game);
void				player_a_util(t_game *game);
void				player_d(t_game *game);
void				player_d_util(t_game *game);
void				load_player(t_game *game);
void				load_player_2(t_game *game);
void				chech_exit(t_game *game);
void				delete_player_texture(t_game *game);
void				delete_player_image(t_game *game);

#endif
