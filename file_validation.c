/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 23:02:21 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/12 17:55:15 by nlowe            ###   ########.fr       */
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

int		valid_place(char *str)
{
	if (!(*str) || *str != '#')
		return (0);
	if (*(str + 1) && *(str + 1) == '#')
		return (1);
	else if (*(str - 1) && *(str - 1) == '#')
		return (1);
	else if (*(str + 5) && *(str + 5) == '#')
		return (1);
	else if (*(str - 5) && *(str - 5) == '#')
		return (1);
	return (0);
}

int		test_character(char *str)
{
	if (*str == '#' && valid_place(str))
		return (1);
	else if (*str == '.')
		return (-1);
	else
		ft_exit("The file provided is not valid.\nError: char test fail");
	return (0);
}

int		test_eol(char *str, int *count, int *lines)
{
	printf("**str**\n%s\ncount = %i\nlines = %i\n", str, *count, *lines);
	if (*lines > 3)
		ft_exit("The file provided is not valid.\nError: number of lines fail");
	if (!(*(str + 1)) || *(str + 1) == '\n')
	{
		if (*count == -8 && *lines == 3)
		{
			printf("double eol\n");
			*lines = 0;
			*count = 0;
			str = str + 1;
			return (1);
		}
		else
			ft_exit("The file provided is not valid.\nError: eol test fail");
	}
	else
	{
		printf("normal eol\n");
		(*lines)++;
	}
	return (0);
}

int		num_of_pieces(char *str)
{
	int	lines;
	int	pieces;
	int	count;

	lines = 0;
	pieces = 0;
	count = 0;

	while (*str)
	{
		if (*str == '\n')
			pieces = pieces + test_eol(str, &count, &lines);
		else
			count = count + test_character(str);
		str++;
	}
	if (pieces == 0 || pieces > 26)
		ft_exit("The file provided is not valid.\nError: num pieces test fail");
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
