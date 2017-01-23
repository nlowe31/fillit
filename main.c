/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:15:30 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/23 15:53:46 by nlowe            ###   ########.fr       */
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
	int		tetriminos;
	char	*contents;

	if (ac != 2)
		ft_exit("usage: fillit filename");
	contents = read_file(av[1]);
	tetriminos = num_of_pieces(contents);
	list = create_list(contents, tetriminos);
	for_each(list, crop_piece);
	launch(list, tetriminos);
	return (0);
}
