/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamd <ael-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:15:19 by aklaikel          #+#    #+#             */
/*   Updated: 2022/10/03 16:25:44 by ael-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdint.h>
# include <mlx.h>
# include<stdbool.h>

# define LEFT 0
# define RIGHT 2
# define BACKWARD 1
# define FORWARD 13
# define ESPACE 49
# define ROWLEFT 123
# define ROWRIGHT 124

# define ESC 53

# define BUFFER_SIZE 1000000

# define SCREENW 1048
# define MINIMAPW 300
# define SCREENH 900
# define MINIMAPH 300

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor[3];
	int		ceiling[3];
	char	**map;
	int		x;
	int		height;
	int		width;
	int		y;
	char	direction;
}	t_data;

typedef struct s_image
{
	unsigned int	*adr_data;
	void			*image;
	uint32_t		floor;
	uint32_t		ciel;
	int				height;
	int				width;
	int				bpp;
	int				sl;
	int				endian;
}				t_image;

typedef struct s_keypress {
	int	a;
	int	d;
	int	s;
	int	w;
	int	rl;
	int	rr;
}				t_keypress;

typedef struct s_argb {
	uint8_t	b;
	uint8_t	g;
	uint8_t	r;
	uint8_t	a;
}				t_argb;

typedef union s_color {
	uint32_t	color;
	t_argb		argb;
}				t_color;

typedef struct s_vector {
	double	x;
	double	y;
}				t_vector;
typedef struct s_pos {
	int	x;
	int	y;
}				t_pos;

typedef struct s_cub {
	t_data		data;
	t_vector	postion;
	t_vector	direction;
	t_vector	plan;
	t_vector	nextside;
	t_vector	camera;
	t_vector	raydirection;
	t_vector	whichwall;
	t_pos		whatdirection;
	t_pos		map;
	t_keypress	smooth;
	void		*mlx_window;
	void		*mlx_ptr;
	int			whichside;
	int			wallhit;
	double		walldistance;
	double		wallx;
	double		textpos;
	t_pos		text;
	double		pos;
	double		step;
	t_image		tv;
	t_image		no;
	t_image		so;
	t_image		we;
	t_image		ea;
	t_image		*draw;
}	t_cub;

typedef double	t_angle;

char	**ft_split(char const *s, char c);
int		ft_strlen(const char *s);
int		ft_strlen_2d(char **s);
void	ft_free(char **str);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
char	**ft_read(int fd);
void	ft_strcpy(char *dir, char *s);
int		max_lenght(char **s);
void	str_cpy_2d(char **str, t_data *data);

int		pos_map(char **file);
int		ft_check_if_map(char **file);
char	get_directions(char	*s);
int		check_path(char *s);
int		check_color(char *s, t_data *data, char d);
int		alloc_str(char *s, t_data *data, char d, int size);
int		if_color(char *s);
int		get_map(char **file, t_data *data);
int		rempl_description_map(char **file, t_data *data);
int		check_first_last_line(char	*str);
int		get_last_line(t_data data);
int		check_element(char	*str);
int		check_player(t_data *data);
int		check_map(t_data data);
void	ft_null(t_data *data);
void	ft_free_all(t_data *data);

// raycasting

void	raycastcub3d(t_data data);
void	rotate_vec(t_vector *dst, t_vector *vctr, t_angle teta);
void	key_listner(t_cub *cub);
void	move_forward(t_cub *cub);
void	move_backward(t_cub *cub);
void	move_right(t_cub *cub);
void	move_left(t_cub *cub);
int		ft_exit(t_cub *cub);
int		key_release(int key, t_cub *cub);
int		key_press(int key, t_cub *cub);
void	minimap(t_cub *cub);
void	multiple_vec_nbr(t_vector *vctr, t_angle multi);
void	rotate_vec(t_vector *dst, t_vector *vctr, t_angle teta);
void	dda_algorithm(t_cub *cub);
void	colors(t_cub *cub);
void	loading(t_cub *cub);
void	drawtoscreen(t_cub *cub, int x);
int		game(t_cub *cub);
void	_free_(t_cub *cub);

#endif