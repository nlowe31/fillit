/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:26:05 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/19 14:25:26 by nlowe            ###   ########.fr       */
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
/*
sqrt(tetrminos * 4);
*/