/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 23:02:21 by nlowe             #+#    #+#             */
/*   Updated: 2017/01/02 12:36:52 by nlowe            ###   ########.fr       */
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
