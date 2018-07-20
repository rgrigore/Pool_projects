/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 10:32:16 by rgrigore          #+#    #+#             */
/*   Updated: 2017/09/03 17:25:20 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TD str[j] == '*' || str[j] == '/' || str[j] == '%'
#define PM str[j] == '+' || (str[j] == '-' && str[j + 1] == ' ')

int		ft_len(char *nr)
{
	int i;

	i = 0;
	while (nr[i])
		i++;
	return (i - 1);
}

int		int_len(int nr)
{
	int	c;

	c = 0;
	while (nr)
	{
		c++;
		nr /= 10;
	}
	return (c);
}

char	*rem_par(char *str, int x)
{
	int	j;
	int i;
	int b;

	b = 0;
	j = x;
	while (str[j] && b == 0 && str[j] != 41)
	{
		if (TD || PM)
			b = 1;
		j++;
	}
	if (b == 0)
	{
		i = x;
		while (str[i] && str[i] != 41)
			i++;
		while (str[i++])
			str[i - 1] = str[i];
		j = x - 1;
		while (str[++j])
			str[j] = str[j + 1];
	}
	return (str);
}

int		is_solved(char *str)
{
	int j;

	j = -1;
	while (str[++j])
		if (str[j] == '*' || str[j] == '/' || str[j] == '+'
				|| (str[j] == '-' && str[j + 1] == ' ') || str[j] == '%')
			return (0);
	return (1);
}

int		ft_atoi(char *str)
{
	int sign;
	int nr;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	nr = 0;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		nr = nr * 10 + sign * (*str - '0');
		str++;
	}
	return (nr);
}
