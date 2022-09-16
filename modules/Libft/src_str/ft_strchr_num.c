/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:46:19 by kyoulee           #+#    #+#             */
/*   Updated: 2022/06/10 07:42:33 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strchr_num(char **str)
{
	long	num;
	int		flag;

	num = 0;
	flag = 0;
	while (0x30 <= **str && **str <= 0x39)
	{
		num = (num * 10) + **str - 0x30;
		if (!flag && num > 0x7FFFFFFF)
			flag = 1;
		(*str)++;
	}
	if (flag)
		return (-1);
	return ((int)num);
}
