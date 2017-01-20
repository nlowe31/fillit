/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:15:30 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/20 15:04:33 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_exit(char *msg)
{
	if (msg && *msg)
		ft_puterr(msg);
	else
		ft_puterr("An error occurred.");
	exit(0);
}

int		main(int ac, char **av)
{
	t_piece *list;
	t_board	*board;
	int		tetriminos;
	char	*contents;

	if (ac != 2)
		ft_exit("usage: fillit filename");
	contents = read_file(av[1]);
	tetriminos = num_of_pieces(contents);
	list = create_list(contents, tetriminos);
	print_list(&list);
	for_each(list, crop_piece);
	print_list(&list);
	board = new_board(4);
	while (list)
	{
		place_piece(board, list);
		list = list->next;
	}
	print_board(board);
	return (0);
}
