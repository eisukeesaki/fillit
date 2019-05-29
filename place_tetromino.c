/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetromino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:40:32 by eesaki            #+#    #+#             */
/*   Updated: 2019/05/28 19:40:30 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check(char board[][16], t_mino *mino, int x, int y)
{
	int		h;
	size_t	p;

	p = 0;
	while (mino->pattern[p] && board[y])
	{
		h = x;
		while (mino->pattern[p] && h - x < 4)
		{
			if (mino->pattern[p] == '#' && board[y][h] != '.')
				return (0);
			h++;
			p++;
		}
		y++;
	}
	return (1);
}

void	place(char board[][16], t_mino *mino, int x, int y)
{
	int		h;
	size_t	p;

	p = 0;
	while (mino->pattern[p] && board[y])
	{
		h = x;
		while (mino->pattern[p] && h - x < 4)
		{
			if (mino->pattern[p] == '#' && board[y][h] == '.')
				board[y][h] = mino->letter;
			h++;
			p++;
		}
		y++;
	}
}

void	clear(char board[][16], t_mino *mino, int x, int y)
{
	int		h;
	size_t	p;

	p = 0;
	while (mino->pattern[p] && board[y])
	{
		h = x;
		while (mino->pattern[p] && h - x < 4)
		{
			if (mino->pattern[p] == '#')
				board[y][h] = '.';
			h++;
			p++;
		}
		y++;
	}
}
