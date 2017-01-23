/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 12:29:33 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/23 15:53:03 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 4096
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_piece
{
	int				x[4];
	int				y[4];
	char			order;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_board
{
	char			**tab;
	int				size;
}					t_board;

t_piece				*new_piece(char *str, int number);
char				*read_file(char *filename);
void				ft_exit(char *msg);
int					num_of_pieces(char *str);
t_piece				*new_piece(char *str, int number);
void				add_piece(t_piece **start, char *str, int number);
t_piece				*create_list(char *str, int total);
void 				print_list(t_piece **list);
void				crop_piece(t_piece *piece);
void				for_each(t_piece *list, void (*f)(t_piece *));
t_board				*new_board(int size);
t_board				*copy_board(t_board *old);
void				print_board(t_board *board);
t_board				*place_piece(t_board *temp, t_piece *piece, int x, int y);
void				launch(t_piece *list, int tetriminos);

#endif
