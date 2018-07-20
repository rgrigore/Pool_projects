/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:46:24 by rgrigore          #+#    #+#             */
/*   Updated: 2017/08/20 11:16:29 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	rush(int x, int y)
{
	int		i;
	int		j;
	char	v[y][x];

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			v[i][j] = ' ';
			if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
				v[i][j] = 'B';
			if ((i == 0 && j == x - 1) || (i == y - 1 && j == x - 1))
				v[i][j] = 'C';
			if ((i == 0 && j == 0) || (i == y - 1 && j == 0))
				v[i][j] = 'A';
			ft_putchar(v[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}