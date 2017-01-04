/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 12:29:33 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/04 14:51:47 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"
#include <stdlib.h>
#include <string.h>

typedef struct		s_piece
{
	char			tab[4][4];
	char			order;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_board
{
	char			**tab;
	int				size;
}					t_board;

t_piece		*new_piece(char *str, int number);

#endif