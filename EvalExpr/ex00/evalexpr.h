/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 11:12:18 by rgrigore          #+#    #+#             */
/*   Updated: 2017/09/03 18:11:56 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALEXPR_H
# define EVALEXPR_H

int		eval_expr(char *str);
int		ft_len(char *nr);
char	*rem_par(char *str, int x);
int		is_solved(char *str);
int		ft_atoi(char *str);
int		value(char *str, int x, int y);
int		int_len(int nr);
void	filler_1(char *str, int i, int j, int m);
void	filler_2(char *str, int i, int j, int m);
char	*priority(char *str, int i, int j, int m);
char	*rem_par(char *str, int x);

#endif
