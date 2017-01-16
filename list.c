/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:39:28 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/16 13:51:20 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_piece(t_piece piece)
{
	int i;

	ft_putstr("Print Piece\n");


	i = 0;
	ft_putstr("Order: ");
	ft_putchar(piece.order);
	ft_putstr("\nCoordinates:\n");
	while (i++ < 4)
	{
		ft_putstr("(");
		ft_putnbr(piece.x[i]);
		ft_putstr(", ");
		ft_putnbr(piece.y[i]);
		ft_putstr(")\n");
	}
}

void 		print_list(t_piece **list)
{
	t_piece		*temp;

	ft_putstr("Print List\n");

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

	ft_putstr("Add Piece\n");

	temp = *start;
	if (temp)
	{
		while (temp->next != NULL)
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

	ft_putstr("New Piece\n");

	coord = 0;
	pos = 0;
	if (!(ret = (t_piece *)malloc(sizeof(*ret))))
		return (NULL);
	ret->next = NULL;
	ret->order = 'A' + number;
	while (pos < 20)
	{
		if (str[pos] == '#')
		{
			ret->x[coord] = pos % 5;
			ret->y[coord] = pos / 5;
			coord++;
		}
		pos++;
	}
	return (ret);
}

t_piece		**create_list(char *str, int total)
{
	t_piece	**ret;
	int		i;

	ft_putstr("Create List\n");
	ret = NULL;
	i = 0;
	while (i < total)
	{
		add_piece(ret, str, i);
		if (*(str + 21))
			str = str + 21;
		i++;
	}
	return (ret);
}
