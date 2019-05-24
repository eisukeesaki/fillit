/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 21:14:55 by eesaki            #+#    #+#             */
/*   Updated: 2019/05/24 12:21:34 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_board(char board[][16], int board_size)
{
	int y;

	y = 0;
	while (y < board_size)
	{
		write(1, board[y], board_size);
		write(1, "\n", 1);
		y++;
	}
}

int		fillit(t_mino **minos)
{
	char	board[16][16];
	int		board_size;

	if (!minos)
		return (0);
	board_size = fill_board(board, minos);
	if (board_size < 0)
		return (0);
	print_board(board, board_size);
	return (1);
}

void	free_minos(t_mino **minos)
{
	t_mino	*mino;
	int		i;

	i = 0;
	while ((mino = minos[i]) != NULL)
	{
		free(minos[i]);
		i++;
	}
	free(minos);
}

int		main(int ac, char **av)
{
	int		fd;
	t_mino	**minos;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit input_file");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (1);
	}
	minos = fd_to_minos(fd);
	close(fd);
	if (!fillit(minos))
	{
		ft_putendl("error");
		return (1);
	}
	free_minos(minos);
	return (0);
}
