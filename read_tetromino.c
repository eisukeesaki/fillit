/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetromino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 22:45:26 by eesaki            #+#    #+#             */
/*   Updated: 2019/05/24 11:57:51 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetromino.h"
#include "fillit.h"

static int		read_input(const int fd, char *buff)
{
	int		rc;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (0);
	while (1)
	{
		if ((rc = read(fd, buff, BUFF_SIZE)) == 0)
			break;
	}
	if (rc == -1)
		return (0);
	return (1);
}

static char		**buff_to_raw_minos(size_t mino_ct, char *input)
{
	char	**raw_minos;
	size_t	head;
	size_t	i;

	head = 0;
	i = 0;
	if (!(raw_minos = ft_memalloc(sizeof(char *) * (mino_ct + 1))))
		return (NULL);
	while (i < mino_ct)
	{
		raw_minos[i] = ft_strsub(input, head, 21);
		head = head + 21;
		i++;
	}
	return (raw_minos);
}

static t_mino	**raw_minos_to_minos(size_t mino_ct, char **raw_minos)
{
	size_t	i;
	t_mino	**minos;
	char	letter;

	i = 0;
	if (!(minos = ft_memalloc(sizeof(t_mino *) * mino_ct + 1)))
		return (NULL);
	letter = 'A';
	while (raw_minos[i])
	{
		minos[i] = str_to_mino(raw_minos[i]);
		minos[i]->letter = letter;
		letter++;
		i++;
	}
	return (minos);
}

static void		free_raw_minos(char **raw_minos)
{
	int i;

	i = 0;
	while (raw_minos[i])
	{
		free(raw_minos[i]);
		i++;
	}
	free(raw_minos);
}

t_mino			**fd_to_minos(int const fd)
{
	char	input[INPUT_MAX];
	size_t	mino_ct;
	char	**split_minos;
	t_mino	**minos;

	if (!(read_input(fd, input)))
		return (NULL);
	if (!(mino_ct = ft_strlen(input) / 21) % 21)
		return (NULL);
	if (!(split_minos = buff_to_raw_minos(mino_ct, input)))
		return (NULL);
	minos = raw_minos_to_minos(mino_ct, split_minos);
	free_raw_minos(split_minos);
	return (minos);
}

