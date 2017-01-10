/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 23:02:21 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/10 18:45:44 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*read_file(char *filename)
{
	int		fd;
	int		ret;
	char	*contents;

	contents = ft_strnew(BUFF_SIZE);
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		ft_exit("An error occurred while opening the file.");
	while ((ret = read(fd, contents, BUFF_SIZE)))
		contents[ret] = '\0';
	return (contents);
}

int		num_of_pieces(char *str)
{
	int	lines;
	int	pounds;
	int	pieces;
	int	other;

	lines = 0;
	pounds = 0;
	pieces = 0;
	other = 0;

	while (*str)
	{
		if (*str == '#')
			pounds++;
		else if (*str == '\n')
			lines++;
		else if (*str == '.')
			other++;
		else
			ft_exit("The file provided is not valid.");
		printf("lines = %i\npounds = %i\npieces = %i\nother = %i\n---\n", lines, pounds, pieces, other);
		if ((*(str + 1) == '\0' && lines == 4) || lines == 5)
		{
			if (pounds != 4 || other != 12)
				ft_exit("The file provided is not valid.");
			pieces++;
			lines = 0;
			pounds = 0;
			other = 0;
		}
		str++;
	}
	if (pieces == 0 || pieces > 26)
		ft_exit("The file provided is not valid.");
	return (pieces);
}
/*
int		check_line(int fd)
{
	char	str[5];
	int		i;

	i = 0;
	read(fd, str, 5);
	while (i++ < 4)
		if (str[i] != '#' || str[i] != '.')
			return (0);
	if (str[i] != '\n')
		return (0);
	return (1);
}

char	*load_piece_type(int type)
{
	char	*pieces[5];

	if (type > 4)
		return (NULL);
	pieces[0] = "##..\n#...\n#...\n....\n";
	pieces[1] = "##..\n##..\n....\n....\n";
	pieces[2] = "#...\n#...\n#...\n#...\n";
	pieces[3] = "##..\n.##.\n....\n....\n";
	pieces[4] = "###.\n.#..\n....\n....\n";
	return (pieces[type]);
}

int		get_piece_type(char str)
{
	char	piece[4][4];
	int		i;
	int		j;

	i = 0;
	pos = 0;
	while (i < 4)
	{
		j = 0;
		while (*str && j < 4)
		{
			piece[i][j] = *str;
			j++;
			str++;
		}
		str++;
		i++;
	}
}
*/
