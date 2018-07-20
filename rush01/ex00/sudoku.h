/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 16:02:01 by rgrigore          #+#    #+#             */
/*   Updated: 2017/08/26 18:57:17 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

int		mast_check(char **str, char table[9][9], int num);
int		it_fits(char table[9][9], int x, int y);
void	copy_table(char table[9][9], int x, int y);
void	sudoku(char table[9][9], int x, int y);
int		is_full(char table[9][9]);
char	g_table[9][9];
int		g_num;

#endif
