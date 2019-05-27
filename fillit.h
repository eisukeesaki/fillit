/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:40:14 by eesaki            #+#    #+#             */
/*   Updated: 2019/05/26 18:40:15 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 546
# define INPUT_MAX 546

# include "libft/libft.h"
# include "tetromino.h"
# include <unistd.h>
# include <fcntl.h>

t_mino	**fd_to_minos(int const fd);
t_mino	*str_to_mino(char *input);
int		fill_board(char board[][16], t_mino **minos);
int		check(char board[][16], t_mino *mino, int x, int y);
void	place(char board[][16], t_mino *mino, int x, int y);
void	clear(char board[][16], t_mino *mino, int x, int y);

#endif
