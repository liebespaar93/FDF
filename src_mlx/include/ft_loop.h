/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:12:07 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/13 08:25:44 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOOP_H
# define FT_LOOP_H

int		ft_key_update(t_screan *screan, t_keyboard *keyboard);
int		ft_mouse_update(t_screan *screan, t_mouse *mouse);
void	ft_mlx_key_mouse_set(t_param *param);

#endif