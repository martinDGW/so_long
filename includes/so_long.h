/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:05:46 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/02/15 16:13:37 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

# define true 1

//========MAP CAM========//
# define WIDTH 15
# define HEIGHT 10

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct	s_tiles
{
	void	*img;
	void	*empty;
	void	*wall;
	void	*player;
	void	*collec;
	void	*end;
	void	*ennemies;
	int		x[1];
	int		y[1];
}	t_tiles;

typedef	struct	s_items
{
	int	collec;
	int	exit;
	int	player;
	int	ennemies;
	int	valid;
}	t_items;

typedef	struct	s_player
{
	int	x;
	int	y;
}	t_player;


typedef struct	s_data
{
	char		**map;
	t_vars		*vars;
	t_tiles		*tiles;
	t_items		*items;
	t_player	*player;
	int			x_max;
	int			y_max;
	int			e_x;
	int			e_y;
	int			step;
	int			last_step;
	int			loop;
	int			ct;
}	t_data;

typedef struct s_card
{
	int	x;
	int	y;
	int	dir;
	int	step;
	int	last_step;
}	t_card;

int			get_ymax(char **map);
int			get_xmax(char **map);
//============INIT=============//
void		init_x_y_max(t_data *data);
void		win_init(t_data *data);
int			struct_init(t_data *data);
int			game_init(t_data *data, int fd);
void		player_pos(t_data *data, char **map);
void		exit_init(t_data *data, char **map);
int			map_init(t_data *data, int fd);
void		setup_tiles(t_tiles *tiles, void *mlx);
void		put_imgs(t_data *data, t_tiles *tiles, t_vars *vars, char **map);
void		put_cam(t_data *data, t_tiles *tiles, t_vars *vars, char **map);

//============ADD=======//
void		ft_free(t_data *data);
size_t		ft_modlen(char **map);
int			ft_err(t_data *data, int fd);
int			ft_err_map(t_data *data, int fd);

//============PARAMS===========//
int			ft_key(int keycode, t_data *data);
int			ft_close(t_data *data);
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_right(t_data *data);
void		move_left(t_data *data);
void		ft_step(t_data *data);
void		dir_up(void *mlx, t_tiles *tiles, int step);
void		dir_down(void *mlx, t_tiles *tiles, int step);
void		dir_right(void *mlx, t_tiles *tiles, int step);
void		dir_left(void *mlx, t_tiles *tiles, int step);
void		end_game(t_data *data);
int			render_frame(t_data *data);
void		anime_rabbit(t_vars *vars, t_tiles *tiles);

//===========PARSING===========//
int			map_check(char **map);
void		check_err(t_data *data);
int			is_map_closed(char **map);
int			is_rect_map(char **map);

//=============GNL=============//
char		*get_next_line(int fd);

//=============XPM LINK=========//
# define WALL "./imgs/wall/forest.xpm"
# define TREE "./imgs/wall/tree.xpm"
# define EMPTY "./imgs/ground/grass8.xpm"
# define P_FRONT "./imgs/player/girl_front.xpm"
# define P_F_RIGHT "./imgs/player/girl_front_rightfeet.xpm"
# define P_F_LEFT "./imgs/player/girl_front_leftfeet.xpm"
# define P_BACK "./imgs/player/girl_back.xpm"
# define P_B_RIGHT "./imgs/player/girl_back_rightfeet.xpm"
# define P_B_LEFT "./imgs/player/girl_back_leftfeet.xpm"
# define P_SIDE "./imgs/player/girl_side.xpm"
# define P_S_RIGHT "./imgs/player/girl_side_rightfeet.xpm"
# define P_S_LEFT "./imgs/player/girl_side_leftfeet.xpm"
# define P_LSIDE "./imgs/player/girl_leftside.xpm"
# define P_LS_RIGHT "./imgs/player/girl_leftside_rightfeet.xpm"
# define P_LS_LEFT "./imgs/player/girl_leftside_leftfeet.xpm"
# define RABBIT_D "./imgs/collect/white_rabbit.xpm"
# define RABBIT_M "./imgs/collect/white_rabbit2.xpm"
# define RABBIT_U "./imgs/collect/white_rabbit3.xpm"
# define END_CLOSE "./imgs/exit/rabbit_hole_close.xpm"
# define END_OPEN "./imgs/exit/rabbit_hole_open.xpm"
# define SPADE_LS "./imgs/ennemies/spade_card.xpm"
# define SPADE_LS_RF "./imgs/ennemies/spade_rightfeet.xpm"
# define SPADE_LS_LF "./imgs/ennemies/spade_leftfeet.xpm"
# define SPADE_RS "./imgs/ennemies/spade_os_card.xpm"
# define SPADE_RS_RF "./imgs/ennemies/spade_os_rightfeet.xpm"
# define SPADE_RS_LF "./imgs/ennemies/spade_os_leftfeet.xpm"
# define HEART_LS "./imgs/ennemies/heart_card.xpm"
# define HEART_LS_RF "./imgs/ennemies/heart_rightfeet.xpm"
# define HEART_LS_LF "./imgs/ennemies/heart_leftfeet.xpm"
# define HEART_RS "./imgs/ennemies/heart_os_card.xpm"
# define HEART_RS_RF "./imgs/ennemies/heart_os_rightfeet.xpm"
# define HEART_RS_LF "./imgs/ennemies/heart_os_leftfeet.xpm"

#endif