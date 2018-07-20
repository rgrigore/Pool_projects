/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:28:55 by rgrigore          #+#    #+#             */
/*   Updated: 2017/09/06 15:44:40 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <unistd.h>

int		check_lines(int len, int rows);
int		verif(int x, int y, int siz);
void	bsq(int x, int y);
char	g_sp;
char	g_obs;
char	g_sq;
int		g_i;
int		g_j;
char	**g_map;
int		g_rows;
int		g_len1;
int		g_posx;
int		g_posy;
int		g_siz;
int		g_busto;

#endif
