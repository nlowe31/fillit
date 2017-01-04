/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 23:02:21 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/04 14:34:05 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		check_line(int fd)
{
	char	str[5];
	int		i;

	read(fd, str, 5);
	while (i++ < 4)
		if (str[i] != '#' || str[i] != '.')
			return (0);
	if (str[i] != '\n')
		return (0);
	return (1);
}

int		check_file(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY))
	if (fd < 0)
		return (0);
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

int		get_piece_type(char str);
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
