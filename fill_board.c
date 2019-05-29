/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:38:25 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/28 19:40:21 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	board_is_ok(char board[][16], int bsize, t_mino **minos, int piece)
{
	t_mino	*mino;
	int		y;
	int		x;

	mino = minos[piece];
	if (!mino)
		return (1);
	y = 0;
	while (y < bsize - mino->height + 1)
	{
		x = 0;
		while (x < bsize - mino->width + 1)
		{
			if (check(board, mino, x, y))
			{
				place(board, mino, x, y);
				if (board_is_ok(board, bsize, minos, piece + 1))
					return (1);
				clear(board, mino, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	sqrt_round_up(int n)
{
	int root;

	root = 0;
	while (root * root < n)
		root++;
	return (root);
}

static int	num_minos(t_mino **minos)
{
	int mino_count;

	mino_count = 0;
	while (minos[mino_count])
		mino_count++;
	return (mino_count);
}

int			fill_board(char board[][16], t_mino **minos)
{
	int	board_size;

	ft_memset(board, '.', 256);
	board_size = sqrt_round_up(num_minos(minos) * 4 + check_parity(minos));
	while (!board_is_ok(board, board_size, minos, 0))
		board_size++;
	return (board_size);
}
