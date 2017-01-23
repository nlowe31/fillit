/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_v2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:09:29 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/23 15:54:30 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int		current;

	current = 0;
	while (current <= (nb / 2))
	{
		if ((current * current) == nb)
		{
			return (current);
		}
		current++;
	}
	return (0);
}

int		piece_fits(t_board *board, t_piece *piece, int x, int y)
{
/*
	ft_putstr("Piece fits? ");
	ft_putchar(piece->order);
	ft_putstr(", coord = ");
	ft_putnbr(x);
	ft_putchar(',');
	ft_putnbr(y);
	ft_putchar('\n');
*/
	if ((y + piece->y[3]) >= (board->size) || (x + piece->x[3]) >= (board->size))
					return (0);
	if (board->tab[y + piece->y[0]][x + piece->x[0]] == '.'
		&& board->tab[y + piece->y[1]][x + piece->x[1]] == '.'
			&& board->tab[y + piece->y[2]][x + piece->x[2]] == '.'
				&& board->tab[y + piece->y[3]][x + piece->x[3]] == '.')
					return (1);
	return (0);
}

t_board	*place_piece(t_board *temp, t_piece *piece, int x, int y)
{
	/*
	ft_putstr("Place piece ");
	ft_putchar(piece->order);
	ft_putchar('\n');
	*/
	t_board	*board;
	board = copy_board(temp);
	board->tab[y + piece->y[0]][x + piece->x[0]] = piece->order;
	board->tab[y + piece->y[1]][x + piece->x[1]] = piece->order;
	board->tab[y + piece->y[2]][x + piece->x[2]] = piece->order;
	board->tab[y + piece->y[3]][x + piece->x[3]] = piece->order;
	return (board);
}

t_board		*solve(t_board *board, t_piece *piece, int x, int y)
{
	t_board	*temp;

	temp = NULL;
	if (!piece)
		return (board);
	if (x >= (board->size))
	{
		if (y >= (board->size))
			return (NULL);
		return (solve(board, piece, 0, (y + 1)));
	}
	else if (piece_fits(board, piece, x, y))
	{
		if((temp = solve(place_piece(board, piece, x, y), piece->next, 0, 0)))
			return (temp);
	}
	return (solve(board, piece, (x + 1), y));
}

void	launch(t_piece *list, int tetriminos)
{
	int		size;
	t_board	*board;

	size = 1;

	size = ft_sqrt(tetriminos * 4);
	board = new_board(size);
	while (!((board = solve(board, list, 0, 0))))
	{
		board = new_board(size);
		size++;
	}
	print_board(board);
}
