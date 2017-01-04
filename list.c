/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 14:39:28 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/04 15:40:39 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*new_piece(char *str, int number)
{
	t_piece	*ret;
	int		i;
	int		j;

	if (!(ret = (t_piece *)malloc(sizeof(*ret))))
		return (NULL);
	ret->next = NULL;
	ret->order = 'A' + number;

	i = 0;
	while (i++ < 4)
	{
		j = 0;
		while (*str && j++ < 4 && *str != '\n')
		{
			ret->tab[i][j] = *str;
			str++;
		}
		if (*str && *str == '\n')
			str++;
	}
	return (ret);
}
