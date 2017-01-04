/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:15:30 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/04 14:51:13 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	t_piece	*test;

	if (ac != 2)
	{
		ft_puterr("usage: fillit filename");
		return (0);
	}
	test = new_piece(av[1], 0);
	printf("%c", test->order);
	return (0);
}
