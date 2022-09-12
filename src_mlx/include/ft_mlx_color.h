/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_color.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:36:55 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/07 02:54:20 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_MLX_COLOR_H
# define FT_MLX_COLOR_H

/////***** color *****/////
# define COLOR_RED			0xEB5353
# define COLOR_YELLOW		0xF9D923
# define COLOR_GREEN		0x36AE7C
# define COLOR_BLUE			0x187498
# define COLOR_PURPLE		0xA149FA

#include <ft_param.h>

int	ft_get_color(float percentage, int color1, int color2);
int	ft_color_maker(t_ply *ply, float z);
#endif