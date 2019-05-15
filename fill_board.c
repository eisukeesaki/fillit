/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:38:25 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/14 20:00:21 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetromino.h"
#include "libft.h"

int		board_is_ok(char board[][16], int board_size, t_mino **minos, int piece)
{
	t_mino	*mino;
	int		y;
	int		x;

	mino = minos[piece];
	if (!mino)
		return (1);
	y = 0;
	while (y < board_size - mino->height + 1)
	{
		x = 0;
		while (x < board_size - mino->width + 1)
		{
			if (check(board, mino, x, y))
			{
				place(board, mino, x, y);
				if (board_is_ok(board, board_size, minos, piece + 1))
					return (1);
				clear(board, mino, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	fillit(t_mino **minos)
{
	char board[16][16];
	int board_size;

	ft_memset(board, '.', 256);
	/* TODO initial board size can be adjusted based on number of minos */
	board_size = 3;
	while (!board_is_ok(board, board_size, minos, 0))
		board_size++;
}
