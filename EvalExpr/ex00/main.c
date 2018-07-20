/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 10:35:24 by rgrigore          #+#    #+#             */
/*   Updated: 2017/09/04 11:37:36 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "evalexpr.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	int v[11];
	int i;
	int s;

	s = 1;
	i = 0;
	if (nbr == 0)
		ft_putchar('0');
	if (nbr < 0)
	{
		ft_putchar('-');
		v[i] = (nbr % 10) * -1;
		i++;
		nbr /= -10;
	}
	while (nbr)
	{
		v[i] = nbr % 10;
		nbr /= 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar(v[i] + '0');
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
