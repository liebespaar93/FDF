/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backbuffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:31:53 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/05 18:31:57 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_param.h>

void	ft_backbuffer_put_pixel(int x, int y, int color, t_param *param)
{
	*(int *)(param->back_buffer + (x * 4) + (y * param->size_line)) = color;
}
