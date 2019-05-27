/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:35:49 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/26 16:15:45 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tetromino.h"
#include "check_parity.h"

int		mino_parity(char *pattern)
{
	int i;

	i = 0;
	while (i < 19)
	{
		if (ft_strequ(pattern, g_parity_list[i].pattern))
			return (g_parity_list[i].parity);
		i++;
	}
	return (0);
}

/*
** Returns 1 if the list of minos cannot possibly fit exactly into a rectangle
** due to having an odd parity against one of three patterns (checkboard,
** horizontal stripes, or vertical stripes). Returns 0 otherwise.
*/

int		check_parity(t_mino **minos)
{
	int parity;
	int i;

	if (!minos)
		return (0);
	parity = 0;
	i = 0;
	while (minos[i])
	{
		parity ^= mino_parity(minos[i]->pattern);
		i++;
	}
	if (parity)
		return (1);
	return (0);
}
