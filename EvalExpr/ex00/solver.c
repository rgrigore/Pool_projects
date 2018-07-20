/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 11:15:34 by rgrigore          #+#    #+#             */
/*   Updated: 2017/09/04 12:41:19 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evalexpr.h"
#include <stdlib.h>
#include <stdio.h>

int		calc(int nr1, char sign, int nr2)
{
	if (sign == '*')
		return (nr1 * nr2);
	if (sign == '/')
		return (nr1 / nr2);
	if (sign == '+')
		return (nr1 + nr2);
	if (sign == '-')
		return (nr1 - nr2);
	if (sign == '%')
		return (nr1 % nr2);
	return (0);
}

char	*calc_str(char *nr1, char sign, char *nr2)
{
	int		v[3];
	char	*nr;

	v[0] = calc(ft_atoi(nr1), sign, ft_atoi(nr2));
	v[1] = 1;
	v[2] = int_len(v[0]);
	if (v[0] < 0)
	{
		v[1] = -1;
		v[2]++;
	}
	nr = malloc(sizeof(char*) * (v[2] + 1));
	nr[v[2]] = '\0';
	if (v[0] == 0)
		nr[0] = '0';
	else
		while (--v[2] >= 0)
		{
			if (v[1] == -1 && v[2] == 0)
				nr[v[2]] = '-';
			else
				nr[v[2]] = v[0] % 10 * v[1] + '0';
			v[0] /= 10;
		}
	return (nr);
}

char	*insert(char *str, int x, int y, char *nr)
{
	int i;

	i = -1;
	while (str[y + ++i])
		str[x + i + ft_len(nr)] = str[y + i];
	str[x + i + ft_len(nr)] = '\0';
	i = -1;
	while (nr[++i])
		str[x + i] = nr[i];
	return (str);
}

char	*priority(char *str, int i, int j, int m)
{
	int x;
	int y;

	x = j - 2;
	while (str[x] != ' ' && str[x] && x > m)
		x--;
	y = j + 2;
	while (str[y] != ' ' && str[y] && y < i)
		y++;
	if (str[y] != 41 && str[y] != ' ')
		y++;
	str = insert(str, x + 1, y - 1, calc_str(str + x + 1, str[j], str + j + 1));
	return (str);
}

int		eval_expr(char *str)
{
	int		i;
	int		j;
	int		m;

	while (!is_solved(str))
	{
		i = 0;
		j = 0;
		while (str[i] && str[i] != 41)
			if (str[i++] == 40)
				j = i - 1;
		if (str[i] != 41)
		{
			j = -1;
			i = ft_len(str);
		}
		m = j;
		if (value(str, j, i))
			filler_1(str, i, j, m);
		else
			filler_2(str, i, j, m);
	}
	return (ft_atoi(str));
}
