/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:35:49 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/28 19:16:03 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
