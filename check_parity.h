/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parity.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:36:38 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/26 16:07:21 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_PARITY_H
# define CHECK_PARITY_H

typedef struct				s_mino_parity
{
	char					*pattern;
	int						parity;
}							t_mino_parity;

static const t_mino_parity	g_parity_list[19] =
{
	(t_mino_parity) {"####", 0},
	(t_mino_parity) {"#...#...#...#", 0},
	(t_mino_parity) {"##..##", 0},
	(t_mino_parity) {"##...##", 0},
	(t_mino_parity) {".#..##..#", 0},
	(t_mino_parity) {".##.##", 0},
	(t_mino_parity) {"#...##...#", 0},
	(t_mino_parity) {"###.#", 3},
	(t_mino_parity) {"##...#...#", 3},
	(t_mino_parity) {"..#.###", 3},
	(t_mino_parity) {"#...#...##", 3},
	(t_mino_parity) {"##..#...#", 3},
	(t_mino_parity) {"###...#", 3},
	(t_mino_parity) {".#...#..##", 3},
	(t_mino_parity) {"#...###", 3},
	(t_mino_parity) {"###..#", 6},
	(t_mino_parity) {".#..##...#", 5},
	(t_mino_parity) {".#..###", 6},
	(t_mino_parity) {"#...##..#", 5}
};

int							check_parity(t_mino **minos);

#endif
