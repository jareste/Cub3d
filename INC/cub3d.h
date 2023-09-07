/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:12:20 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 13:31:51 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../LIB/libft/libft.h"
# include "../LIB/minilibx_opengl_20191021/mlx.h"

# define PI 3.14159265359
# define SPEED 0.09
# define TURN 0.05
# define W 13
# define A 0
# define S 1
# define D 2
# define RIGHT 124
# define LEFT 123

# define SUCCESS 1
# define FAILURE 0

# define NO 0
# define FIRST 1
# define SECOND 2
# define BOTH 3

# define HEIGHT 1080
# define WIDTH 1920

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}		t_color;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}		t_image;

typedef struct s_map
{
	char		*tex_n;
	char		*tex_s;
	char		*tex_e;
	char		*tex_o;
	t_color		floor;
	t_color		ceiling;
	char		**map;
	int			n_cols;
	int			n_rows;
}		t_map;

typedef struct s_player
{
	float		locx;
	float		locy;
	float		angle;
	float		dirx;
	float		diry;
	float		planex;
	float		planey;
	int			player;
}		t_player;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_image		img;
	t_image		textures[4];
}		t_mlx;

typedef struct s_key
{
	char		w;
	char		a;
	char		s;
	char		d;
	char		left;
	char		right;
}		t_key;

typedef struct s_game
{
	t_player	player;
	t_map		map;
	t_mlx		mlx;
	t_key		key;
}		t_game;

typedef struct s_check_map
{
	int			i;
	int			found;
	char		*visited;
}		t_check_map;

typedef struct s_ray
{
	float		camerax;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	float		sidedistx;
	float		sidedisty;
	float		deltadistx;
	float		deltadisty;
	float		raydirx;
	float		raydiry;
	float		perpwalldist;
}		t_ray;

typedef struct s_render
{
	int			x;
	t_player	pl;
	t_ray		r;
}			t_render;

//EXIT
int			clean_exit(t_game *game);

//PARSE
int			exit_parse(char *str);
void		free_split(char **split);
int			ft_strlen_n(const char *str);
int			parse(int argc, char **argv, t_game *game);
int			ft_ptrlen(char **str);
int			init(t_game *game);
int			ft_atoi_cub(char *str, int free_args);
int			setup_pl(t_player *player, char coord, int col, int row);
char		*create_string(t_game *game, char c, int size);
char		*create_string(t_game *game, char c, int size);
void		dfs(t_map *m, t_check_map *ch_m, int i, int j);
int			is_map(char *line);
int			read_texture(t_game *game, char *line);
int			read_colour(t_game *game, char *line);
int			read_map(int fd, t_game *game);
int			check_inside(char *line, t_player *player, int *found, int row);
int			check_map(t_game *game, char **map, t_player *player);

//HOOKS

int			key_hook(int key_code, t_game *game);
int			key_hook_release(int key, t_game *game);
int			wasd_moves(t_game *game);
int			rot_moves(t_game *game);
int			mouse_hook(int key, int x, int y, t_game *game);
int			mouse_hook_release(int key, int x, int y, t_game *game);
int			check_correct(char **map, int x, int y);

//RENDER

int			draw_vertical(t_game *game, t_render *rend, int height, int x_tex);
float		FixAng(float a);
void		print_rays(t_game *game);
int			print_win(int key, t_game *game);
int			render(t_game *game);
int			choose_text(t_ray *r);
int			compute_xcoord(t_player *pl, t_ray *r);
float		compute_dist(t_player *pl, t_ray *r);
int			init_render_vars(t_player *pl, t_ray *r, int x);
int			find_dist_to_edge(t_player *pl, t_ray *r);
int			find_collision(t_game *game, t_ray *r);
int			c2int(t_color *c);
void		my_pixel_put(t_image *data, int x, int y, int color);
int			my_pixel_get(t_image *img, int x, int y);
void		print_2d(t_game *game);

#endif