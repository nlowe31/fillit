/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 12:29:33 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/02 12:36:49 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_piece
{
	char			**tab;
	int				num;
	s_piece			*next;
}					t_piece;

typedef struct		s_board
{
	char			**tab;
	int				size;
}					t_board;



#endif
