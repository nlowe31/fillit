/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:26:05 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/23 16:05:50 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board		*new_board(int size)
{
	t_board		*board;
	int			i;

	i = 0;
	if (!(board = (t_board *)malloc(sizeof(t_board))))
		ft_exit(0);
	board->size = size;
	if (!(board->tab = (char **)malloc(sizeof(char*) * (size + 1))))
		ft_exit(0);
	while (i < size)
	{
		if (!(board->tab[i] = (char *)malloc(sizeof(char) * (size + 1))))
			ft_exit(0);
		ft_memset(board->tab[i], '.', size);
		board->tab[i][size] = '\0';
		i++;
	}
	board->tab[i] = 0;
	return (board);
}

t_board		*copy_board(t_board *old)
{
	t_board		*board;
	int			i;

	i = 0;
	if (!(board = (t_board *)malloc(sizeof(t_board))))
		ft_exit(0);
	board->size = old->size;
	if (!(board->tab = (char **)malloc(sizeof(char*) * (board->size + 1))))
		ft_exit(0);
	while (i < board->size)
	{
		if (!(board->tab[i] = ft_strdup(old->tab[i])))
			ft_exit(0);
		i++;
	}
	board->tab[i] = 0;
	return (board);
}

void		print_board(t_board *board)
{
	int		i;

	i = 0;
	while (board->tab[i] && i < board->size)
	{
		ft_putstr(board->tab[i]);
		ft_putchar('\n');
		i++;
	}
}

void		test_place_piece(t_board *board, t_piece *piece)
{
	int		x;
	int		y;

	y = 0;
	while (y < board->size)
	{
		x = 0;
		while (x < board->size)
		{
			if (board->tab[y + piece->y[0]][x + piece->x[0]] == '.'
				&& board->tab[y + piece->y[1]][x + piece->x[1]] == '.'
					&& board->tab[y + piece->y[2]][x + piece->x[2]] == '.'
						&& board->tab[y + piece->y[3]][x + piece->x[3]] == '.')
			{
				board->tab[y + piece->y[0]][x + piece->x[0]] = piece->order;
				board->tab[y + piece->y[1]][x + piece->x[1]] = piece->order;
				board->tab[y + piece->y[2]][x + piece->x[2]] = piece->order;
				board->tab[y + piece->y[3]][x + piece->x[3]] = piece->order;
				return ;
			}
			x++;
		}
		y++;
	}
}
