/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 11:53:21 by rgrigore          #+#    #+#             */
/*   Updated: 2017/09/06 17:24:40 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "bsq.h"
#define IJ g_map[g_i][g_j]

int		measurements(char *fname, int len0, int cont)
{
	char c;

	if ((g_siz = open(fname, O_RDONLY)))
		while (read(g_siz, &c, 1) && cont != 2 && c != '\0')
		{
			if (cont == 1)
				g_len1++;
			else
				len0++;
			if (c == '\n')
				cont++;
			if (c >= '0' && c <= '9' && cont == 0)
			{
				g_rows = g_rows * 10 + (c - '0');
				g_i++;
			}
			else if (cont == 0)
				g_j++;
		}
	close(g_siz);
	while (g_i-- != len0 - 4)
		g_rows /= 10;
	if (cont != 2)
		len0 = 0;
	return (len0);
}

int		carpentry(char *head, int len0, int k)
{
	while (read(k, &head[g_j], 1) && head[g_j] != '\n')
		g_j++;
	head[g_j] = '\0';
	if (!check_lines(len0, g_rows))
		return (0);
	g_sq = head[len0 - 2];
	g_obs = head[len0 - 3];
	g_sp = head[len0 - 4];
	g_i = -1;
	while (++g_i < g_rows)
	{
		g_j = -1;
		while (++g_j < g_len1)
		{
			read(k, &g_map[g_i][g_j], 1);
			if (g_j == g_len1 - 1 && g_map[g_i][g_j] != '\n')
				return (0);
			if (IJ != g_sp && IJ != g_obs && IJ != '\n')
				return (0);
		}
		g_map[g_i][g_j] = '\0';
	}
	close(k);
	bsq(g_i, g_j);
	return (1);
}

void	allocation(char **av, int len0, int a)
{
	char *head;

	head = malloc(sizeof(char*) * len0);
	g_map = malloc(sizeof(char**) * g_rows);
	g_i = -1;
	g_j = 0;
	while (++g_i < g_rows)
		g_map[g_i] = malloc(sizeof(char*) * (g_len1));
	if ((g_siz = open(av[a], O_RDONLY)))
	{
		if (!carpentry(head, len0, g_siz))
			write(2, "map error\n", 10);
	}
	else
		write(2, "map error\n", 10);
}

char	*read_input(char *av)
{
	int c;

	g_siz = open("tmp", O_CREAT | O_TRUNC | O_WRONLY);
	while (read(0, &c, 1))
		write(g_siz, &c, 1);
	close(g_siz);
	av[0] = 't';
	av[1] = 'm';
	av[2] = 'p';
	av[3] = '\0';
	return (av);
}

int		main(int ac, char **av)
{
	int		a;
	int		cont;
	int		len0;

	a = (ac >= 2) ? 0 : -1;
	if (ac < 2)
		av[0] = read_input(av[0]);
	while (++a < ac)
	{
		g_i = 0;
		g_j = 0;
		g_rows = 0;
		g_len1 = 0;
		len0 = 0;
		cont = 0;
		len0 = measurements(av[a], len0, cont);
		if (g_rows != 0 && g_len1 >= 2)
			allocation(av, len0, a);
		else
			write(2, "map error\n", 10);
		if (a != ac - 1)
			write(1, "\n", 1);
	}
	return (0);
}
