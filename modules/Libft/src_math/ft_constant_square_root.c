/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constant_root.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:10:07 by kyoulee           #+#    #+#             */
/*   Updated: 2022/07/11 19:10:09 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* 
	#define C_SQUARE_ROOT_2 1.41421356237309504880168872420969807
	#define C_SQUARE_ROOT_3 1.73205080756887729352744634150587236
	#define C_SQUARE_ROOT_5 2.23606797749978969640917366873127623
	url :: https://en.wikipedia.org/wiki/Square_root
*/
/* ************************************************************************** */

double	ft_constant_square_root(int integer, int repeat)
{
	double	root;
	double	num;

	root = 0.5;
	num = 0;
	while (num < repeat)
	{
		root = 1 + ((integer - 1) / (1 + root));
		num++;
	}
	return (root);
}

double	ft_sqrt(float integer)
{
	double	root;
	double	num;

	root = 0.5;
	num = 0;
	while (num < 21)
	{
		root = 1 + ((integer - 1) / (1 + root));
		num++;
	}
	return (root);
}
