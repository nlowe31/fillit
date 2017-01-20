/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:09:29 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/20 17:10:50 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		piece_fits(t_board *board, t_piece *piece, int x, int y)
{
	if (board->tab[y + piece->y[0]][x + piece->x[0]] == '.'
		&& board->tab[y + piece->y[1]][x + piece->x[1]] == '.'
			&& board->tab[y + piece->y[2]][x + piece->x[2]] == '.'
				&& board->tab[y + piece->y[3]][x + piece->x[3]] == '.')
					return (1);
	return (0);
}

void	place_piece(t_board *board, t_piece *piece, int x, int y)
{
	board->tab[y + piece->y[0]][x + piece->x[0]] = piece->order;
	board->tab[y + piece->y[1]][x + piece->x[1]] = piece->order;
	board->tab[y + piece->y[2]][x + piece->x[2]] = piece->order;
	board->tab[y + piece->y[3]][x + piece->x[3]] = piece->order;
}

void	launch()
{
	/* code */
}
