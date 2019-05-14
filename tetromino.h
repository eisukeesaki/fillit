/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:06:48 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/13 19:13:31 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETROMINO_H
# define TETROMINO_H

typedef struct		s_mino
{
	unsigned char	width;
	unsigned char	height;
	char			pattern[14];
	char			letter;
}					t_mino;

#endif
