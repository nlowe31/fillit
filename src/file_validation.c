/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 23:02:21 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/26 16:14:09 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_file(char *filename)
{
	int		fd;
	int		ret;
	char	*contents;

	contents = ft_strnew(BUFF_SIZE);
	fd = open(filename, O_RDWR);
	if (fd <= 0)
		ft_exit(0);
	if (!(ret = read(fd, contents, BUFF_SIZE)))
		ft_exit(0);
	contents[ret] = '\0';
	close(fd);
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

int		test_character(char *str, int *chars)
{
	(*chars)++;
	if (*str == '#' && valid_place(str))
		return (1);
	else if (*str == '.')
		return (-1);
	else
		ft_exit(0);
	return (0);
}

int		test_eol(char **str, int *count, int *lines, int *chars)
{
	if (*lines > 3 || *chars != 4)
		ft_exit(0);
	*chars = 0;
	if (!(*(*str + 1)) || *(*str + 1) == '\n')
	{
		if (*(*str + 1) == '\n' && !(*(*str + 2)))
			ft_exit(0);
		if (*count == -8 && *lines == 3)
		{
			*lines = 0;
			*count = 0;
			(*str)++;
			return (1);
		}
		else
			ft_exit(0);
	}
	else
		(*lines)++;
	return (0);
}

int		num_of_pieces(char *str)
{
	int	lines;
	int	pieces;
	int	count;
	int	chars;

	lines = 0;
	pieces = 0;
	count = 0;
	chars = 0;
	while (*str)
	{
		if (*str == '\n')
			pieces = pieces + test_eol(&str, &count, &lines, &chars);
		else
			count = count + test_character(str, &chars);
		str++;
	}
	if (pieces == 0 || pieces > 26)
		ft_exit(0);
	return (pieces);
}
