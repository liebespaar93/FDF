
#ifndef MLX_TYPE_H
# define MLX_TYPE_H

typedef struct s_mouse
{
	int	mouse_keycode;

	int x;				// x값
	int y;				// y값

	int draw_x;			// x값
	int draw_y;			// y값
}	t_mouse;

typedef	struct s_param
{
  void	*mlx_ptr;
  void	*win_ptr;

	t_mouse	mouse;

	int x;
	int y;
	int z;
} t_param;

# endif