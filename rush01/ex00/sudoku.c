/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 09:25:20 by rgrigore          #+#    #+#             */
/*   Updated: 2017/08/27 10:57:19 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"

void	print_table(char table[9][9])
{
	int i;
	int j;

	i = -1;
	while (++i <= 8)
	{
		j = -1;
		while (++j <= 8)
		{
			if (j != 8)
			{
				write(1, &table[i][j], 1);
				write(1, " ", 1);
			}
			else
				write(1, &table[i][j], 1);
		}
		write(1, "\n", 1);
	}
}

int		is_full(char table[9][9])
{
	int i;
	int j;

	i = -1;
	while (++i <= 8)
	{
		j = -1;
		while (++j <= 8)
		{
			if (table[i][j] == '.')
				return (0);
		}
	}
	return (1);
}

int		it_fits(char table[9][9], int x, int y)
{
	int i;
	int j;

	i = -1;
	while (++i <= 8)
		if (table[i][y] == table[x][y] && i != x)
			return (0);
	j = -1;
	while (++j <= 8)
		if (table[x][j] == table[x][y] && j != y)
			return (0);
	i = (x / 3) * 3 - 1;
	while (++i <= (x / 3) * 3 + 2)
	{
		j = (y / 3) * 3 - 1;
		while (++j <= (y / 3) * 3 + 2)
			if (table[i][j] == table[x][y] && (i != x || j != y))
				return (0);
	}
	return (1);
}

void	sudoku(char table[9][9], int x, int y)
{
	char i;

	if (table[x][y] == '.' && g_num <= 1)
	{
		i = '0';
		while (++i <= '9')
		{
			table[x][y] = i;
			if (it_fits(table, x, y))
				copy_table(table, x, y);
			else
				table[x][y] = '.';
		}
	}
	else	if (is_full(table) == 0 && g_num <= 1)
	{
		if (y == 8)
			sudoku(table, x + 1, 0);
		else
			sudoku(table, x, y + 1);
	}
}

int		main(int argc, char **argv)
{
	char	m[9][9];
	int		i;
	int		j;

	g_num = 0;
	i = (argc == 10) ? -1 : 9;
	while (++i <= 8)
	{
		j = -1;
		while (++j <= 8)
		{
			m[i][j] = argv[i + 1][j];
		}
	}
	if (mast_check(argv, m, argc) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	sudoku(m, 0, 0);
	if (g_num == 1)
		print_table(g_table);
	else
		write(1, "Error\n", 6);
	return (0);
}
