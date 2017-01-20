/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:39:28 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/20 15:03:19 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

void		print_piece(t_piece piece)
{
	int i;

	i = 0;
	ft_putstr("Order: ");
	ft_putchar(piece.order);
	ft_putstr("\nCoordinates:\n");
	while (i < 4)
	{
		ft_putstr("(");
		ft_putnbr(piece.x[i]);
		ft_putstr(", ");
		ft_putnbr(piece.y[i]);
		ft_putstr(")\n");
		i++;
	}
}

void 		print_list(t_piece **list)
{
	t_piece		*temp;

	ft_putstr("Print List\n");
	if (!(list))
		ft_exit("Empty list.");
	temp = *list;
	while (temp)
	{
		print_piece(*temp);
		temp = temp->next;
	}
}

void		add_piece(t_piece **start, char *str, int number)
{
	t_piece	*temp;

	temp = (*start);
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new_piece(str, number);
	}
	else
		(*start) = new_piece(str, number);
}

t_piece		*new_piece(char *str, int number)
{
	t_piece	*ret;
	int		coord;
	int		pos;

	coord = 0;
	pos = 0;
	if (!(ret = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	ret->next = NULL;
	ret->order = 'A' + number;
	while (pos < 20)
	{
		if (str[pos] == '#')
		{
			ret->x[coord] = (pos % 5);
			ret->y[coord] = (pos / 5);
			coord++;
		}
		pos++;
	}
	return (ret);
}

t_piece		*create_list(char *str, int total)
{
	t_piece	*ret;
	int		i;

	ret = NULL;
	i = 0;
	while (*str && i < total)
	{
		add_piece(&ret, str, i);
		if (*(str + 21))
			str = str + 21;
		i++;
	}
	return (ret);
}
