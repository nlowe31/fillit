/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:37:15 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/24 21:19:35 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	crop_piece(t_piece *piece)
{
	int		i;
	int		x_min;
	int		y_min;

	i = 0;
	x_min = 3;
	y_min = 3;
	while (i < 4)
	{
		if (piece->x[i] < x_min)
			x_min = piece->x[i];
		if (piece->y[i] < y_min)
			y_min = piece->y[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		piece->x[i] -= x_min;
		piece->y[i] -= y_min;
		i++;
	}
}

void    check_if_separate(t_piece *piece)
{
    int     i;
	int		j;
	int		edges;
	int		singles;
	int		multiples;

	ft_putstr("\npiece: ");
	ft_putchar(piece->order);
	ft_putchar('\n');
    i = 0;
	singles = 0;
	multiples = 0;
		/*
		ft_putnbr(piece->x[i]);
		ft_putnbr(piece->x[i - 1]);
		ft_putchar('\n');
		ft_putnbr(piece->y[i]);
		ft_putnbr(piece->y[i - 1]);
		ft_putchar('\n');
		ft_putchar('\n');
		*/
	while (i < 4)
	{
		j = 0;
		edges = 0;
		while (j < 4)
		{
			ft_putnbr(piece->x[i]);
			ft_putchar(',');
			ft_putnbr(piece->y[i]);
			ft_putchar('\n');
			ft_putnbr(piece->x[j]);
			ft_putchar(',');
			ft_putnbr(piece->y[j]);
			ft_putchar('\n');
			ft_putchar('\n');

			if (piece->x[i] == piece->x[j] && ((piece->y[i] - piece->y[j]) == 1 || (piece->y[i] - piece->y[j]) == -1))
			{
				ft_putendl("x == x");
				edges++;
			}
			if (piece->y[i] == piece->y[j] && ((piece->x[i] - piece->x[j]) == 1 || (piece->x[i] - piece->x[j]) == -1))
			{
				ft_putendl("y == y");
				edges++;
			}
			j++;
		}
		ft_putstr("edges: ");
		ft_putnbr(edges);
		ft_putchar('\n');
		if (edges >= 2)
			multiples++;
		else if (edges > 0)
			singles++;
    	i++;
	}
	ft_putstr("multiples: ");
	ft_putnbr(multiples);
	ft_putstr(", singles: ");
	ft_putnbr(singles);
	ft_putchar('\n');
	if (!(multiples >= 2 && (singles + multiples) == 4))
		ft_exit(0);
}

void	for_each(t_piece *list, void (*f)(t_piece *))
{
	t_piece		*temp;

	temp = list;
	while (temp)
	{
		(*f)(temp);
		temp = temp->next;
	}
}
