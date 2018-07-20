/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 15:22:48 by rgrigore          #+#    #+#             */
/*   Updated: 2017/08/27 10:57:26 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	copy_table(char table[9][9], int x, int y)
{
	int i;
	int j;

	if (is_full(table))
	{
		i = -1;
		while (++i <= 8)
		{
			j = -1;
			while (++j <= 8)
				g_table[i][j] = table[i][j];
		}
		g_num++;
	}
	if (y == 8 && x < 8)
		sudoku(table, x + 1, 0);
	else	if (x <= 8)
		sudoku(table, x, y + 1);
}

int		init_check(char table[9][9])
{
	int i;
	int j;

	i = -1;
	while (++i <= 8)
	{
		j = -1;
		while (++j <= 8)
			if (table[i][j] >= '1' && table[i][j] <= '9')
				if (it_fits(table, i, j) == 0)
					return (0);
	}
	return (1);
}

int		val_check(char table[9][9])
{
	int i;
	int j;

	i = -1;
	while (++i <= 8)
	{
		j = -1;
		while (++j <= 8)
		{
			if ((table[i][j] < '1' || table[i][j] > '9') && table[i][j] != '.')
				return (0);
		}
	}
	return (1);
}

int		len_check(char **str)
{
	int	i;
	int j;

	i = 0;
	while (++i < 10)
	{
		j = 0;
		while (str[i][j] != '\0')
			j++;
		if (j != 9)
			return (0);
	}
	return (1);
}

int		mast_check(char **str, char table[9][9], int num)
{
	if (num == 10)
		if (val_check(table) == 1 && init_check(table) == 1
				&& len_check(str) == 1)
			return (1);
	return (0);
}
