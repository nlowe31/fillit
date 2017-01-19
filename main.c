/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:15:30 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/19 13:40:23 by nlowe            ###   ########.fr       */
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
	char	*contents;

	contents = read_file(av[1]);
	if (ac != 2)
		ft_exit("usage: fillit filename");
	list = create_list(contents, num_of_pieces(contents));
	print_list(&list);
	for_each(list, crop_piece);
	print_list(&list);
	return (0);
}
