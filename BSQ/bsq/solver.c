/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 11:44:05 by rgrigore          #+#    #+#             */
/*   Updated: 2017/09/06 15:44:30 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#define AB (i >= g_posx && i <= g_posx + g_siz - 1)

int		check_lines(int len, int rows)
{
	int cont;

	cont = 0;
	while (rows)
	{
		cont++;
		rows /= 10;
	}
	if (len != cont + 4)
		return (0);
	return (1);
}

void	print_map(void)
{
	int i;
	int j;

	i = -1;
	while (++i < g_rows)
	{
		j = -1;
		while (++j < g_len1)
			if (AB && (j >= g_posy && j <= g_posy + g_siz - 1) && g_siz != 0)
				write(1, &g_sq, 1);
			else
				write(1, &g_map[i][j], 1);
		free(g_map[i]);
	}
	free(g_map);
}

int		verif(int x, int y, int siz)
{
	int i;
	int j;

	i = x;
	while (i <= x + siz && i < g_rows)
	{
		j = y;
		while (j <= y + siz && j < g_len1)
		{
			if (g_map[i][j] == g_obs)
			{
				g_busto = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	bsq_split(int x, int y, int c, int i)
{
	c = 0;
	while (c == 0)
	{
		i = x - 1;
		while (++i <= x + g_siz && c == 0)
			if (g_map[i][y + g_siz] == g_obs || x + g_siz >= g_rows)
			{
				c = 1;
				g_busto = y + g_siz;
			}
		i = y + g_siz;
		while (--i >= y && c == 0)
			if (g_map[x + g_siz][i] == g_obs || y + g_siz >= g_len1 - 1)
			{
				c = 1;
				g_busto = i;
			}
		if (c == 0)
		{
			g_siz++;
			g_posx = x;
			g_posy = y;
		}
	}
}

void	bsq(int x, int y)
{
	int i;
	int c;

	g_siz = 0;
	x = -1;
	i = 0;
	c = 0;
	while (++x < g_rows - g_siz)
	{
		y = -1;
		while (++y < g_len1 - 1 - g_siz)
		{
			g_busto = y;
			if (verif(x, y, g_siz) && g_siz < g_rows && g_siz < g_len1)
				bsq_split(x, y, c, i);
			y += g_busto - y;
		}
	}
	print_map();
}
