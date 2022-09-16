/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dimension.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:16:19 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/28 09:16:22 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DIMENSION_H
# define FT_DIMENSION_H

# include <libft.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct dimensional_zero			t_d_zero;
typedef struct dimensional_one			t_d_one;
typedef struct dimensional_two			t_d_two;
typedef struct dimensional_three		t_d_three;
typedef struct dimensional_four			t_d_four;
typedef struct dimensional_axis			t_d_axis;
typedef union u_dimensional_option		t_d_option;

typedef union u_dimensional_option
{
	int	option;

	struct s_dimension
	{
		bool	p_1 : 1;
		bool	m_1 : 1;
		bool	p_2 : 1;
		bool	m_2 : 1;
		bool	p_3 : 1;
		bool	m_3 : 1;
		bool	p_4 : 1;
		bool	m_4 : 1;
	}	s_bit;
}	t_d_option;

typedef struct dimensional_axis
{
	int			dimension;
	t_d_option	axis;
	int			order[4];
}	t_d_axis;

typedef struct dimensional_zero
{
	char	*data_type;
	void	*data;

	int		coordinate;
}	t_d_zero;

typedef struct dimensional_one
{
	t_d_zero	*d_0;

	int			coordinate_1;

	t_d_one		*head1;
	t_d_one		*connect1_p;
	t_d_one		*connect1_m;
}	t_d_one;

typedef struct dimensional_two
{
	t_d_zero	*d_0;
	t_d_one		*d_1;

	int			coordinate_1;
	int			coordinate_2;

	t_d_two		*head1;
	t_d_two		*head2;
	t_d_two		*connect1_p;
	t_d_two		*connect1_m;
	t_d_two		*connect2_p;
	t_d_two		*connect2_m;
}	t_d_two;

typedef struct dimensional_three
{
	t_d_zero	*d_0;
	t_d_two		*d_2;

	int			coordinate_1;
	int			coordinate_2;
	int			coordinate_3;

	t_d_three	*head1;
	t_d_three	*head2;
	t_d_three	*head3;
	t_d_three	*connect1_p;
	t_d_three	*connect1_m;
	t_d_three	*connect2_p;
	t_d_three	*connect2_m;
	t_d_three	*connect3_p;
	t_d_three	*connect3_m;
}	t_d_three;

typedef struct dimensional_four
{
	t_d_zero	*d_0;
	t_d_three	*d_3;

	int			coordinate_1;
	int			coordinate_2;
	int			coordinate_3;
	int			coordinate_4;

	t_d_four	*head1;
	t_d_four	*head2;
	t_d_four	*head3;
	t_d_four	*head4;
	t_d_four	*connect1_p;
	t_d_four	*connect1_m;
	t_d_four	*connect2_p;
	t_d_four	*connect2_m;
	t_d_four	*connect3_p;
	t_d_four	*connect3_m;
	t_d_four	*connect4_p;
	t_d_four	*connect4_m;
}	t_d_four;

//## src_axis ##//
// ft_axis_init.c //
t_d_axis	ft_axis_init(int option, int dimension);
t_d_axis	ft_axis_order(t_d_axis axis, int *order);
int			ft_dimension(int dimension);
int			ft_axis(int axis);
// ft_axis_controller.c //
t_d_axis	ft_axis_switch(t_d_axis axis, int order1, int order2);
t_d_axis	ft_axis_move(t_d_axis axis, int move);
// ft_axis_view.c //
int			ft_axis_out(int option);
int			ft_axis_opp(int option);

//## src_dimensional_zero ##//
// ft_d_zero_new.c //
t_d_zero	*ft_d_zero_new(void *data, char *data_type);

//## src_dimensional_one ##//
// ft_d_one_new.c //
t_d_one		*ft_d_one_new(t_d_zero *d_0);
// ft_d_one_connect1.c //
t_d_one		*ft_d_one_connect1_p(t_d_one *d_standard, t_d_one *d_new);
t_d_one		*ft_d_one_connect1_m(t_d_one *d_standard, t_d_one *d_new);
// ft_d_one_head.c //
t_d_one		*ft_d_one_head(t_d_one *d_1, int option);
// ft_d_one_addr.c //
t_d_one		*ft_d_one_addr(t_d_one *d_1, int option);
// ft_d_one_switch.c //
t_d_one		*ft_d_one_switch_zero(t_d_one *d_1, t_d_zero *d_0, int option);
t_d_one		*ft_d_one_switch_one(t_d_one *d_standard, t_d_one *d_new, \
	int option);
// ft_d_one_connect.c //
t_d_one		*ft_d_one_connect_zero(t_d_one *d_1, t_d_zero *d_0, int option);
t_d_one		*ft_d_one_connect_one(t_d_one *d_standard, t_d_one *d_next, \
	int option);

//## src_dimensional_two ##//
// ft_d_two_new.c //
t_d_two		*ft_d_two_new(t_d_one *d_1);
// ft_d_two_connect1.c //
t_d_two		*ft_d_two_connect1_p(t_d_two *d_standard, t_d_two *d_new);
t_d_two		*ft_d_two_connect1_m(t_d_two *d_standard, t_d_two *d_new);
// ft_d_two_connect2.c //
t_d_two		*ft_d_two_connect2_p(t_d_two *d_standard, t_d_two *d_new);
t_d_two		*ft_d_two_connect2_m(t_d_two *d_standard, t_d_two *d_new);
// ft_d_two_head.c //
t_d_two		*ft_d_two_head(t_d_two *d_2, int option);
// ft_d_two_addr.c //
t_d_two		*ft_d_two_addr(t_d_two *d_2, int option);
// ft_d_two_connect.c //
t_d_two		*ft_d_two_connect_zero(t_d_two *d_2, t_d_zero *d_0, int option);
t_d_two		*ft_d_two_connect_one(t_d_two *d_2, t_d_one *d_1, int option);
t_d_two		*ft_d_two_connect_two(t_d_two *d_standard, t_d_two *d_next, \
	int option);
// ft_d_two_switch.c //
t_d_two		*ft_d_two_switch_zero(t_d_two *d_2, t_d_zero *d_0, int option);
t_d_two		*ft_d_two_switch_one(t_d_two *d_2, t_d_one *d_1, int option);
t_d_two		*ft_d_two_switch_two(t_d_two *d_standard, t_d_two *d_next, \
	int option);
// ft_d_two_connect_axis_one.c //
t_d_two		*ft_d_two_connect_axis1_one(t_d_two *d_2, t_d_one *d_1, \
	t_d_axis axis2, t_d_axis axis1);
t_d_two		*ft_d_two_connect_axis2_one(t_d_two *d_2, t_d_one *d_1, \
	t_d_axis axis2, t_d_axis axis1);
// ft_d_two_connect_axis_two.c //
t_d_two		*ft_d_two_connect_axis1_two(t_d_two *d_standard, t_d_two *d_next, \
	t_d_axis axis2_1, t_d_axis axis2_2);

//## src_dimensional_three ##//
// ft_d_three_new.c //
t_d_three	*ft_d_three_new(t_d_two *d_2);
// ft_d_three_connect1.c //
t_d_three	*ft_d_three_connect1_p(t_d_three *d_standard, t_d_three *d_new);
t_d_three	*ft_d_three_connect1_m(t_d_three *d_standard, t_d_three *d_new);
// ft_d_three_connect2.c //
t_d_three	*ft_d_three_connect2_p(t_d_three *d_standard, t_d_three *d_new);
t_d_three	*ft_d_three_connect2_m(t_d_three *d_standard, t_d_three *d_new);
// ft_d_three_connect3.c //
t_d_three	*ft_d_three_connect3_p(t_d_three *d_standard, t_d_three *d_new);
t_d_three	*ft_d_three_connect3_m(t_d_three *d_standard, t_d_three *d_new);
// ft_d_three_head.c //
t_d_three	*ft_d_three_head(t_d_three *d_3, int option);
// ft_d_three_addr.c //
t_d_three	*ft_d_three_addr(t_d_three *d_3, int option);
// ft_d_three_connect.c //
t_d_three	*ft_d_three_connect_zero(t_d_three *d_3, t_d_zero *d_0, int option);
t_d_three	*ft_d_three_connect_two(t_d_three *d_3, t_d_two *d_2, int option);
t_d_three	*ft_d_three_connect_three(t_d_three *d_standard, t_d_three *d_next, \
	int option);
// ft_d_three_switch.c //
t_d_three	*ft_d_three_switch_zero(t_d_three *d_3, t_d_zero *d_0, int option);
t_d_three	*ft_d_three_switch_two(t_d_three *d_3, t_d_two *d_2, int option);
t_d_three	*ft_d_three_switch_three(t_d_three *d_standard, t_d_three *d_next, \
	int option);
// ft_d_three_connect_axis_two.c //
t_d_three	*ft_d_three_connect_axis1_two(t_d_three *d_3, t_d_two *d_2, \
	t_d_axis axis3, t_d_axis axis2);
t_d_three	*ft_d_three_connect_axis2_two(t_d_three *d_3, t_d_two *d_2, \
	t_d_axis axis3, t_d_axis axis2);
t_d_three	*ft_d_three_connect_axis3_two(t_d_three *d_3, t_d_two *d_2, \
	t_d_axis axis3, t_d_axis axis2);
// ft_d_three_connect_axis_three.c //
t_d_three	*ft_d_three_connect_axis1_three(t_d_three *d_standard, \
	t_d_three *d_next, t_d_axis axis3_1, t_d_axis axis3_2);
t_d_three	*ft_d_three_connect_axis2_three(t_d_three *d_standard, \
	t_d_three *d_next, t_d_axis axis3_1, t_d_axis axis3_2);

//## src_dimensional_four ##//
// ft_d_four_new.c //
t_d_four	*ft_d_four_new(t_d_three *d_3);
// ft_d_four_connect1.c //
t_d_four	*ft_d_four_connect1_p(t_d_four *d_standard, t_d_four *d_new);
t_d_four	*ft_d_four_connect1_m(t_d_four *d_standard, t_d_four *d_new);
// ft_d_four_connect2.c //
t_d_four	*ft_d_four_connect2_p(t_d_four *d_standard, t_d_four *d_new);
t_d_four	*ft_d_four_connect2_m(t_d_four *d_standard, t_d_four *d_new);
// ft_d_four_connect3.c //
t_d_four	*ft_d_four_connect3_p(t_d_four *d_standard, t_d_four *d_new);
t_d_four	*ft_d_four_connect3_m(t_d_four *d_standard, t_d_four *d_new);
// ft_d_four_connect4.c //
t_d_four	*ft_d_four_connect4_p(t_d_four *d_standard, t_d_four *d_new);
t_d_four	*ft_d_four_connect4_m(t_d_four *d_standard, t_d_four *d_new);
// ft_d_four_head.c //
t_d_four	*ft_d_four_head(t_d_four *d_4, int option);
// ft_d_four_addr.c //
t_d_four	*ft_d_four_addr(t_d_four *d_4, int option);
// ft_d_four_connect.c //
t_d_four	*ft_d_four_connect_zero(t_d_four *d_4, t_d_zero *d_0, int option);
t_d_four	*ft_d_four_connect_three(t_d_four *d_4, t_d_three *d_3, int option);
t_d_four	*ft_d_four_connect_four(t_d_four *d_standard, t_d_four *d_next, \
	int option);
// ft_d_four_switch.c //
t_d_four	*ft_d_four_switch_zero(t_d_four *d_4, t_d_zero *d_0, int option);
t_d_four	*ft_d_four_switch_three(t_d_four *d_4, t_d_three *d_3, int option);
t_d_four	*ft_d_four_switch_four(t_d_four *d_standard, t_d_four *d_next, \
	int option);
// ft_d_four_connect_axis_three.c //
t_d_four	*ft_d_four_connect_axis1_three(t_d_four *d_4, t_d_three *d_3, \
	t_d_axis axis4, t_d_axis axis3);
t_d_four	*ft_d_four_connect_axis2_three(t_d_four *d_4, t_d_three *d_3, \
	t_d_axis axis4, t_d_axis axis3);
t_d_four	*ft_d_four_connect_axis3_three(t_d_four *d_4, t_d_three *d_3, \
	t_d_axis axis4, t_d_axis axis3);
t_d_four	*ft_d_four_connect_axis4_three(t_d_four *d_4, t_d_three *d_3, \
	t_d_axis axis4, t_d_axis axis3);
// ft_d_four_connect_axis_three_utils //
void		ft_d_four_connect_axis2_1_three_utils(t_d_four *d_new, \
	t_d_three *d_3, t_d_axis axis4, t_d_axis axis3);
void		ft_d_four_connect_axis2_2_three_utils(t_d_four *d_next, \
	t_d_four *d_4, t_d_axis axis4, t_d_axis axis3);
void		ft_d_four_connect_axis3_1_three_utils(t_d_four *d_4, \
	t_d_four *d_temp, t_d_axis axis4, t_d_axis axis3);
void		ft_d_four_connect_axis3_2_three_utils(t_d_four *d_4, \
	t_d_four *d_temp, t_d_axis axis4, t_d_axis axis3);
t_d_four	*ft_d_four_connect_axis3_3_three_utils(t_d_four *d_4, \
	t_d_four *d_next, t_d_axis axis4, t_d_axis axis3);
// ft_d_four_connect_axis_four.c //
t_d_four	*ft_d_four_connect_axis1_four(t_d_four *d_standard, \
	t_d_four *d_next, t_d_axis axis4_1, t_d_axis axis4_2);
#endif