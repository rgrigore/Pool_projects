/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliaries2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 16:39:50 by rgrigore          #+#    #+#             */
/*   Updated: 2017/09/03 18:17:17 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evalexpr.h"

int		value(char *str, int x, int y)
{
	int i;

	i = x;
	while (++i < y)
		if (str[i] == '*' || str[i] == '/' || str[i] == '%')
			return (1);
	return (0);
}

void	filler_1(char *str, int i, int j, int m)
{
	while (++j <= i)
		if (str[j] == '*' || str[j] == '/' || str[j] == '%')
		{
			str = priority(str, i, j, m);
			str = rem_par(str, m);
			break ;
		}
}

void	filler_2(char *str, int i, int j, int m)
{
	while (++j <= i)
		if (str[j] == '+' || (str[j] == '-' && str[j + 1] == ' '))
		{
			str = priority(str, i, j, m);
			str = rem_par(str, m);
			break ;
		}
}
