/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:09:29 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/20 19:08:46 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		piece_fits(t_board *board, t_piece *piece, int x, int y)
{

	ft_putstr("Piece fits? coord = ");
	ft_putnbr(x);
	ft_putchar(',');
	ft_putnbr(y);
	ft_putchar('\n');

	if ((x + piece->y[3]) >= board->size || (y + piece->x[3]) >= board->size)
					return (0);
	if (board->tab[y + piece->y[0]][x + piece->x[0]] == '.'
		&& board->tab[y + piece->y[1]][x + piece->x[1]] == '.'
			&& board->tab[y + piece->y[2]][x + piece->x[2]] == '.'
				&& board->tab[y + piece->y[3]][x + piece->x[3]] == '.')
					return (1);
	return (0);
}

void	place_piece(t_board *board, t_piece *piece, int x, int y)
{
	ft_putstr("Place piece\n");

	board->tab[y + piece->y[0]][x + piece->x[0]] = piece->order;
	board->tab[y + piece->y[1]][x + piece->x[1]] = piece->order;
	board->tab[y + piece->y[2]][x + piece->x[2]] = piece->order;
	board->tab[y + piece->y[3]][x + piece->x[3]] = piece->order;
}
/*
int		solve(t_board *board, t_piece *piece)
{
	int		x;
	int		y;


	ft_putstr("Solve, size = ");
	ft_putnbr(board->size);
	ft_putstr(", order = ");
	ft_putchar(piece->order);
	ft_putchar('\n');


	y = 0;
	while (y < board->size)
	{
		x = 0;
			while (x < board->size)
			{
				if (piece_fits(board, piece, x, y))
				{
					place_piece(board, piece, x, y);
					if (!(piece->next))
						return (1);
					return(solve(board, piece->next));
				}
				x++;
			}
		y++;
	}
	return (0);
}
*/
int		solve(t_board *board, t_piece *piece, int x, int y)
{
	if (!(piece))
		return (1);
	if (x >= (board->size - 1))
	{
		if (y >= (board->size - 1))
			return (0);
		return(solve(board, piece, 0, (y + 1)));
	}
	else if (piece_fits(board, piece, x, y))
	{
		place_piece(board, piece, x, y);
		return(solve(board, piece->next, 0, 0));
	}
	return (solve(board, piece, (x + 1), (y + 1)));
}

void	launch(t_piece *list, int size, int x, int y)
{
	t_board *board;

	board = new_board(size);
	if (solve(board, list, x, y))
	{
		print_board(board);
		return ;
	}
	else if (x < (size - 1))
		launch(list, size, (x + 1), y);
	else if (y < (size - 1))
		launch(list, size, (x + 1), y);
	else
		launch(list, (size + 1), 0, 0);
}
/*
void	launch(t_piece *list, int tetriminos)
{
	int		size;
	t_board	*board;

	size = 1;

	//size = sqrt(tetriminos * 4);
	board = new_board(size);
	while (!(solve(board, list, 0, 0)))
	{
		board = new_board(size);
		size++;
	}
	print_board(board);
}
*/
