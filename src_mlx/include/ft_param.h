/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:45:48 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 10:55:27 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARAM_H
# define FT_PARAM_H

# define WIN_WIDTH   1000
# define WIN_HEIGHT  700

# define CANVAS_X		0
# define CANVAS_Y		0
# define CANVAS_WIDTH	WIN_WIDTH
# define CANVAS_HEIGHT	WIN_HEIGHT

# include <ft_basis.h>
# include <ft_screan.h>
# include <ft_matrix.h>
# include <ft_mac_keyboard.h>
# include <ft_mac_mouse.h>
# include <ft_polygon.h>

typedef struct s_param	t_param;

typedef struct s_param
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*buffer;
	char		*back_buffer;
	int			bits_per_pixel;
	int			size_line;
	int			endian;

	t_screan	*screan;
	t_basis2	*basis2;
	t_mtx2		m2_angle;

	t_ply		*ply;

	t_keyboard	*keyboard;
	t_mouse		*mouse;

}	t_param;

t_param	*ft_param_free(t_param **param_ptr);
t_param	*ft_param_init(void);
#endif