/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 21:14:55 by eesaki            #+#    #+#             */
/*   Updated: 2019/05/23 21:14:56 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetromino.h"
#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		ft_putendl("invalid number of arguments.");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_putendl("file open error");
	fillit(fd_to_minos(fd));
	close(fd);
	return (0);
}

