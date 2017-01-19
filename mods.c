/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:37:15 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/19 13:39:39 by nlowe            ###   ########.fr       */
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
