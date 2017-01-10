/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:15:30 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/10 17:37:16 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

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
//	t_piece	*test

	if (ac != 2)
		ft_exit("usage: fillit filename");
	printf("%i\n", num_of_pieces(read_file(av[1])));
//	test = new_piece(av[1], 0);
//	printf("%c", test->order);
	return (0);
}
